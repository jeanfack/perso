#include <iostream>
#include <thread>
#include <vector>

using namespace std;


ostream& operator<<(ostream& os, const vector<unsigned long> v)
{
    if (v.empty())
        os << "[]";
    else
    {
        os << "[" << v[0];

        for (unsigned long i = 1; i < v.size(); ++i)
            os << "," << v[i];

        os << "]";
    }

    return os;
}

void f1(unsigned long (&a)[10], unsigned long i)
{
    a[i] = i * i;
}

void f2(unsigned long a, unsigned long b)
{
    cout << a * b;
}

int main()
{
    vector<unsigned long> a(10);

    for (unsigned long i = 0; i < 10; ++i)
        a[i] = 0;

    vector<thread> tv;
    for (unsigned long i = 0; i < 10; ++i)
        tv.emplace_back(thread([&a](unsigned long i){ a[i] =  i * i;}, i));

    
    for (unsigned long i = 0; i < 10; ++i)
        tv[i].join();

    cout << "a:" << a << endl;
}
