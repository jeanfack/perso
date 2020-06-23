#include <iostream>
#include <exception>

using namespace std;


struct Scoped
{
    Scoped(string s) : s(s) { cout << s << endl; }
    ~Scoped() { cout << "~" << s << endl; }

    const string s;
};

int main()
{
    bool ok(false);

    Scoped a("A");

    try
    {
        Scoped a("B");

        if (ok)
            cout << "ok" << endl;
        else 
            throw 10;
    }
    catch (int i)
    {
        cout << "exception:" << i << endl;
    }

    cout << "fin" << endl;
}