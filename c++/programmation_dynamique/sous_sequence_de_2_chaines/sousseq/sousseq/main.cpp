#include <iostream>  // std::cin, std::cout
#include <string>    // std::string
#include <utility>   // std::pair


using namespace std;


/////////////////////////////
//
// CONSTANT
//
/////////////////////////////
constexpr unsigned long N_MAX = 100;


/////////////////////////////
//
// declaration class
//
/////////////////////////////
struct Input;


/////////////////////////////
//
// declaration function
//
/////////////////////////////
template<typename T> T read();
pair<unsigned long, string> subseq(const Input& in);
pair<unsigned long, string> subseq(const string& x, const string& y);
ostream& operator<<(ostream& os, const pair<unsigned long, string>& p);
void readTestcases(unsigned long T);


/////////////////////////////
//
// definition class
//
/////////////////////////////
struct Input
{
    Input() : x(read<string>()), y(read<string>())
    {
    }

    const string x;
    const string y;
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

pair<unsigned long, string> subseq(const Input& in)
{
    return subseq(in.x, in.y);
}

pair<unsigned long, string> subseq(const string& x, const string& y)
{
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    //
    // lssj[i][j] = "longueur d'une plus longue sous sequence commune aux prefix de longueur i+1 de y, et au prefixe de longueur j+1 de x
    // 
    // lssj[i][0] = 0 pour 0 <= i < x.size()
    // lssj[0][j] = 0 pour 0 <= j < y.size()
    // lssj[i+1][j+1] = lssj[i][j] + 1 avec i,j> 0 et x[i] == y[j]
    // lssj[i+1][j+1] = max(lssj[i+1][j], lssj[i][j+1]) avec i,j> 0 et x[i] != y[j]
    //
    /////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    static pair<unsigned long, string> lssj[N_MAX+1][N_MAX+1];


    lssj[0][0] = pair<unsigned long, string>(0, string(""));
    for (unsigned int i = 0; i < x.size(); ++i)
    {
        lssj[i + 1][0] = pair<unsigned long, string>(0, string(""));
        for (unsigned int j = 0; j < y.size(); ++j)
        {
            lssj[0][j + 1] = pair<unsigned long, string>(0, string(""));
            if (x[i] == y[j])
                lssj[i+1][j+1] = pair<unsigned long, string>(lssj[i][j].first + 1, lssj[i][j].second + x[i]);
            else
            //{   // SOLUTION1: pas d'ordre sur la sous chaine
            //    if (lssj[i + 1][j].first > lssj[i][j + 1].first)
            //        lssj[i + 1][j + 1] = lssj[i + 1][j];
            //    else if (lssj[i + 1][j].first < lssj[i][j + 1].first)
            //        lssj[i + 1][j + 1] = lssj[i][j + 1];
            //}
            {   // SOLUTION2: sous chaine minimale
                if (lssj[i + 1][j].first > lssj[i][j + 1].first)
                    lssj[i + 1][j + 1] = lssj[i + 1][j];
                else if (lssj[i + 1][j].first < lssj[i][j + 1].first)
                    lssj[i + 1][j + 1] = lssj[i][j + 1];
                else
                {
                    if (lssj[i + 1][j].second < lssj[i][j + 1].second) // en cas d'egalité de longueur, prendre la chaine la plus petit
                        lssj[i + 1][j + 1] = lssj[i + 1][j];
                    else
                        lssj[i + 1][j + 1] = lssj[i][j + 1];
                }
            }
        }
    }

    return lssj[x.size()][y.size()];
}

ostream& operator<<(ostream& os, const pair<unsigned long, string>& p)
{
    os << "<" << p.first << "," << p.second << ">";

    return os;
}

void readTestcases(unsigned long T)
{
    for (unsigned long i = 0; i < T; ++i)
    {
        cout << subseq(Input()) << endl;
    }
}

int main()
{
    readTestcases(read<unsigned long>());

    return 0;
}
