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
        terminate(); // une exception non géré appel terminate() qui appel abort().
    }

    cout << "fin" << endl; // jamais affiché en cas d'exception
    // Le destructeur de "A" n'est pas jamais appelé en cas d'exception
}
