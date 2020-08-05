#include <iostream>  // cout
#include <chrono>

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

void UnoptimizedLoop(char* s)
{
        for (size_t i = 0; i < strlen(s); ++i)
            if (s[i] == ' ')
                s[i] = '*';
}

void LoopCacheEnd(char* s)
{
    for (size_t i = 0, end = strlen(s); i < end; ++i)
        if (s[i] == ' ')
            s[i] = '*';
}

int main()
{
    {
        char s[] = "This string has many space (0x20) chars. ";
        AutoTimer<chrono::nanoseconds>("UnoptimizedLoop(ns):");
        UnoptimizedLoop(s);
    }

    {
        char s[] = "This string has many space (0x20) chars. ";
        AutoTimer<chrono::nanoseconds>("LoopCacheEnd(ns):");
        LoopCacheEnd(s);
    }

    return 0;
}