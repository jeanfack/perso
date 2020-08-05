#include <iostream>  // std::cin, std::cout
#include <vector>    // std::vector


using namespace std;


/////////////////////////////
//
// declaration class
//
/////////////////////////////
struct Emplacement;
struct Input;
struct Intervalle;

/////////////////////////////
//
// declaration function
//
/////////////////////////////
istream& operator>>(istream& is, Emplacement& e);
template<typename T> T read();
template<typename T> vector<T> readVector(unsigned long N);
vector<unsigned long> compute(const Input& in);
vector<unsigned long> compute(unsigned long N, const vector<Emplacement>& T);
unsigned long previousPosition(unsigned long i, const vector<Emplacement>& v);
ostream& operator<<(ostream& os, const vector<unsigned long>& v);
void readTestcases(unsigned long T);


/////////////////////////////
//
// definition class
//
/////////////////////////////
struct Emplacement
{
    Emplacement(unsigned long position, unsigned long annualGain, unsigned long distanceToPreserve) : position(position), annualGain(annualGain), distanceToPreserve(distanceToPreserve)
    {
    }

    Emplacement() : Emplacement(0, 0, 0)
    {
    }

    unsigned long position;
    unsigned long annualGain;
    unsigned long distanceToPreserve;
};

struct Input
{
    Input() : N(read<unsigned long>()), v(readVector<Emplacement>(N))
    {
    }

    const unsigned long N;
    const vector<Emplacement> v;
};

/////////////////////////////
//
// definition function
//
/////////////////////////////
istream& operator>>(istream& is, Emplacement& e)
{
    is >> e.position;
    is >> e.annualGain;
    is >> e.distanceToPreserve;

    return is;
}

template<typename T> T read()
{
    T n;
    cin >> n;
    return n;
}

template<typename T> vector<T> readVector(unsigned long N)
{
    vector<T> v(N);

    for (unsigned long i = 0; i < N; ++i)
        v[i] = read<T>();
    return v;
}

vector<unsigned long> compute(const Input& in)
{
    return compute(in.N, in.v);
}

vector<unsigned long> compute(unsigned long N, const vector<Emplacement>& v)
{
    vector<pair<unsigned long, vector<unsigned long>>> r(N);

    r[0] = pair<unsigned long, vector<unsigned long>>(v[0].annualGain,vector<unsigned long>{0});

    for (unsigned long i = 1; i < N; ++i)
    {

        unsigned long e_i(previousPosition(i, v));
        
        unsigned long tmpMax;
        vector<unsigned long> tmpV;

        if (e_i > 0)
        {
            tmpMax = r[e_i-1].first + v[i].annualGain;
            tmpV = r[e_i-1].second;
            tmpV.push_back(i);
        }
        else
        {
            tmpMax = v[i].annualGain;
            tmpV = vector<unsigned long>{ i };
        }

        if (tmpMax > r[i - 1].first)
            r[i] = pair<unsigned long, vector<unsigned long>>(tmpMax, tmpV);
        else
            r[i] = r[i - 1];


    }

    return r[N-1].second;
}

unsigned long previousPosition(unsigned long i, const vector<Emplacement>& v)
{
    for (unsigned long j = i; j > 0; --j)
    {
        if (v[i].position - v[j - 1].position >= v[i].distanceToPreserve)
            return j;
    }

    return 0;
}

ostream& operator<<(ostream& os, const vector<unsigned long>& v)
{
    if (v.empty())
        os << "<>";
    else
    {
        os << "<" << v[0];

        for (unsigned long i = 1; i < v.size(); ++i)
            os << "," << v[i];

        os << ">";
    }

    return os;
}

void readTestcases(unsigned long T)
{
    for (unsigned long i = 0; i < T; ++i)
    {
        cout << compute(Input()) << endl;
    }
}

int main()
{
    readTestcases(read<unsigned long>());

    return 0;
}
