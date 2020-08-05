#include <iostream>  // cout
#include <chrono>    // chrono
#include<vector>     // vector
#include<numeric>    // accumulate
#include <execution> // execution
#include<cassert>    // assert


#pragma warning(disable:26444)


template<typename T_TICK> class AutoTimer {
public:
    // clears the timer
    AutoTimer(const char* msg) : msg(msg), start(std::chrono::system_clock::now())
    {
    }

    ~AutoTimer()
    {
        std::cout << msg << GetDuration() << std::endl;
    }

    // get the number of nanoseconds since the timer was started
    long long GetDuration()
    {
        return std::chrono::duration_cast<T_TICK>(std::chrono::system_clock::now() - start).count();
    }

private:
    const char* msg;
    std::chrono::system_clock::time_point start;
};


using namespace std;


constexpr unsigned long N_MAX(10000000);


unsigned long long sum_v1(vector<unsigned long>& a)
{
    return accumulate(a.cbegin(), a.cend(), 0ull, [](unsigned long long u, unsigned long long v) { return u + v;});
}

unsigned long long sum_v2(vector<unsigned long>& a)
{
    return reduce(a.cbegin(), a.cend(), 0ull, [](unsigned long long u, unsigned long long v) { return u + v; });
}

unsigned long long sum_v3(vector<unsigned long>& a)
{
    return reduce(execution::par, a.cbegin(), a.cend(), 0ull, [](unsigned long long u, unsigned long long v) { return u + v; });
}

int main()
{
    vector<unsigned long> a(N_MAX);

    for (unsigned long i = 0; i < N_MAX; ++i)
        a[i] = i + 1;


    {
        unsigned long long sum;
        {
            AutoTimer<chrono::milliseconds>("sum_v1(milliseconds): ");
            AutoTimer<chrono::microseconds>("sum_v1(microseconds): ");
            AutoTimer<chrono::nanoseconds>("sum_v1(nanoseconds): ");
            sum = sum_v1(a);
        }

        cout << "sum == " << sum << endl;
        assert(sum == (unsigned long long)N_MAX * (N_MAX + 1) / 2);
    }

    {
        unsigned long long sum;
        {
            AutoTimer<chrono::milliseconds>("sum_v2(milliseconds): ");
            AutoTimer<chrono::microseconds>("sum_v2(microseconds): ");
            AutoTimer<chrono::nanoseconds>("sum_v2(nanoseconds): ");
            sum = sum_v2(a);
        }

        cout << "sum == " << sum << endl;
        assert(sum == (unsigned long long)N_MAX * (N_MAX + 1) / 2);
    }

    {
        unsigned long long sum;
        {
            AutoTimer<chrono::milliseconds>("sum_v3(milliseconds): ");
            AutoTimer<chrono::microseconds>("sum_v3(microseconds): ");
            AutoTimer<chrono::nanoseconds>("sum_v3(nanoseconds): ");
            sum = sum_v3(a);
        }

        cout << "sum == " << sum << endl;
        assert(sum == (unsigned long long)N_MAX * (N_MAX + 1) / 2);
    }


    return 0;
}
