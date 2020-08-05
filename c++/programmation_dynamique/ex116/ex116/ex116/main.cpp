#include <iostream>  // std::cin, std::cout
#include <vector>    // std::vector
#include <utility>   // std::pair
#include <algorithm> // std::max


using namespace std;


/////////////////////////////
//
// declaration class
//
/////////////////////////////
struct Input;
struct Intervalle;

/////////////////////////////
//
// declaration function
//
/////////////////////////////
template<typename T> T read();
template<typename T> vector<T> readVector(unsigned long N);
pair<unsigned long, unsigned long> compute(const Input& in);
pair<unsigned long, unsigned long> compute(unsigned long N, const vector<unsigned long>& T);
void print(const vector<unsigned long>& T, const vector<unsigned long>& MI, const vector<unsigned long>& CH, unsigned long k, const pair<unsigned long, unsigned long>& p_max);
ostream& operator<<(ostream& os, const pair<unsigned long, unsigned long>& p);
void readTestcases(unsigned long T);


/////////////////////////////
//
// definition class
//
/////////////////////////////
struct Input
{
    Input() : N(read<unsigned long>()), T(readVector<unsigned long>(N))
    {
    }

    const unsigned long N;
    const vector<unsigned long> T;
};

struct Intervalle
{
    Intervalle() : p(0, 0)
    {
    }

    Intervalle(unsigned long a, unsigned long b) : p(a, b)
    {
    }

    Intervalle(const pair<unsigned long, unsigned long>& p) : p(p)
    {
    }

    unsigned long d() const
    {
        return p.second - p.first;
    }

    Intervalle& operator=(const Intervalle& other)
    {
        if (this != &other)
            p = other.p;

        return *this;
    }

    pair<unsigned long, unsigned long> p;
};

/////////////////////////////
//
// definition function
//
/////////////////////////////
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

pair<unsigned long, unsigned long> compute(const Input& in)
{
    return compute(in.N, in.T);
}

pair<unsigned long, unsigned long> compute(unsigned long N, const vector<unsigned long>& T)
{
    vector<unsigned long> MI(N);
    vector<unsigned long> CH(N);

    MI[0] = 0;
    CH[0] = 0;
    unsigned long mi_max(MI[0]);
    pair<unsigned long, unsigned long> p_max(0, 0);
    //print(T, MI, CH, 0, p_max);
    for (unsigned int k = 1; k < N; ++k)
    {
        if (MI[k - 1] + T[k] > T[k - 1])
        {
            MI[k] = MI[k - 1] + T[k] - T[k - 1];
            CH[k] = CH[k - 1];
            if (MI[k] > mi_max)
            {
                mi_max = MI[k];
                p_max = pair<unsigned long, unsigned long>(CH[k], k);
            }
        }
        else
        {
            MI[k] = 0;
            CH[k] = k;
        }

        //print(T, MI, CH, k, p_max);
    }

    return pair<unsigned long, unsigned long>(T[p_max.first], T[p_max.second]);
}

void print(const vector<unsigned long>& T, const vector<unsigned long>& MI, const vector<unsigned long>& CH, unsigned long k, const pair<unsigned long, unsigned long>& p_max)
{
    cout << "k:" << k << " T[" << k << "]:" << T[k] << " MI[" << k << "]" << MI[k] << " CH[" << k << "]" << CH[k] << "(i,j):" << p_max << "inter:" << pair<unsigned long, unsigned long>(T[p_max.first], T[p_max.second]) << endl;
}

ostream& operator<<(ostream& os, const pair<unsigned long, unsigned long>& p)
{
    os << "<" << p.first << "," << p.second << ">";

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
