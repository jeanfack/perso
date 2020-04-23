#include <iostream>   // cin, cout
#include <string>     // string
#include <vector>     // vector
#include <algorithm>  // sort


using namespace std;


/////////////////////////////
//
// declaration class
//
/////////////////////////////
struct Input;
template<typename T_INT, typename T_UNSIGNED_INT, T_UNSIGNED_INT T_N> struct SuffixArray;
template<typename T_INT, typename T_UNSIGNED_INT, T_UNSIGNED_INT T_N> struct SuffixArraySubstring;

/////////////////////////////
//
// declaration function
//
/////////////////////////////
template<typename T> ostream& operator<<(std::ostream& os, const vector<T>& o);
template<typename T> T read();
template<typename T> void read(T& obj);
void readTestcases(unsigned long T);
void compute(const Input& in);
void compute(const string& s);


/////////////////////////////
//
// definition class
//
/////////////////////////////
struct Input
{
    Input() : s(read<string>())
    {
    }

    const string s;
};

template<typename T_ALPHABET, typename T_UNSIGNED_INT, T_UNSIGNED_INT T_N> struct SuffixArray
{
    struct Suffix
    {
        Suffix() : index(0), rank{ 0,0 }
        {
        }

        T_UNSIGNED_INT index;  // To store original index 
        T_ALPHABET rank[2]; // To store ranks and next rank pair 
    };

    struct Array
    {
        T_UNSIGNED_INT suffix[T_N];
        T_UNSIGNED_INT lcp[T_N];
    };



    static void build(const string& txt, Array& arr)
    {
        buildSuffix(txt, arr.suffix);
        buildLcp(txt, arr.suffix, arr.lcp);
    }

    static bool cmp(Suffix& a, Suffix& b)
    {
        return (a.rank[0] == b.rank[0]) ? (a.rank[1] < b.rank[1] ? true : false) :
            (a.rank[0] < b.rank[0] ? true : false);
    }

    static void buildSuffix(const string& txt, T_UNSIGNED_INT( &dst)[T_N])
    {
        buildSuffix(txt, static_cast<T_UNSIGNED_INT>(txt.size()), dst);
    }

    // This is the main function that takes a string 'txt' of size n as an 
// argument, builds and return the suffix array for the given string 
    static void buildSuffix(const string& txt, T_UNSIGNED_INT n, T_UNSIGNED_INT(&dst)[T_N])
    {
        // A structure to store suffixes and their indexes 
        static Suffix suffixes[T_N];

        // Store suffixes and their indexes in an array of structures. 
        // The structure is needed to sort the suffixes alphabatically 
        // and maintain their old indexes while sorting 
        for (T_UNSIGNED_INT i = 0; i < n; i++)
        {
            suffixes[i].index = i;
            suffixes[i].rank[0] = txt[i] /* - 'A'*/;
            suffixes[i].rank[1] = ((i + 1) < n) ? (txt[i + 1]/* - 'A'*/) : -1;
        }

        // Sort the suffixes using the comparison function 
        // defined above. 
        sort(begin(suffixes), begin(suffixes) + n, cmp);

        // At his point, all suffixes are sorted according to first 
        // 2 characters.  Let us sort suffixes according to first 4 
        // characters, then first 8 and so on 
        static T_UNSIGNED_INT ind[T_N];  // This array is needed to get the index in suffixes[] 
        // from original index.  This mapping is needed to get 
        // next suffix. 
        for (T_UNSIGNED_INT k = 4; k < 2 * n; k = k * 2)
        {
            // Assigning rank and index values to first suffix 
            T_ALPHABET rank = 0;
            T_ALPHABET prev_rank = suffixes[0].rank[0];
            suffixes[0].rank[0] = rank;
            ind[suffixes[0].index] = 0;

            // Assigning rank to suffixes 
            for (T_UNSIGNED_INT i = 1; i < n; ++i)
            {
                // If first rank and next ranks are same as that of previous 
                // suffix in array, assign the same new rank to this suffix 
                if (suffixes[i].rank[0] == prev_rank &&
                    suffixes[i].rank[1] == suffixes[i - 1].rank[1])
                {
                    prev_rank = suffixes[i].rank[0];
                    suffixes[i].rank[0] = rank;
                }
                else // Otherwise increment rank and assign 
                {
                    prev_rank = suffixes[i].rank[0];
                    suffixes[i].rank[0] = ++rank;
                }
                ind[suffixes[i].index] = i;
            }

            // Assign next rank to every suffix 
            for (T_UNSIGNED_INT i = 0; i < n; ++i)
            {
                T_UNSIGNED_INT nextindex = suffixes[i].index + k / 2;
                suffixes[i].rank[1] = (nextindex < n) ?
                    suffixes[ind[nextindex]].rank[0] : -1;
            }

            // Sort the suffixes according to first k characters 
            sort(begin(suffixes), begin(suffixes) + n, cmp);
        }

        for (T_UNSIGNED_INT i = 0; i < n; ++i)
            dst[i] = suffixes[i].index;
    }

    static void buildLcp(const string& txt, T_UNSIGNED_INT(&suffixArr)[T_N] , T_UNSIGNED_INT(&dst)[T_N])
    {
        return buildLcp(txt, suffixArr, static_cast<T_UNSIGNED_INT>(txt.size()), dst);
    }

    /* To construct and return LCP using kasai Algorithm */
    static void buildLcp(const string& txt, T_UNSIGNED_INT(&suffixArr)[T_N], T_UNSIGNED_INT n, T_UNSIGNED_INT(&dst)[T_N])
    {
        // An auxiliary array to store inverse of suffix array 
        // elements. For example if suffixArr[0] is 5, the 
        // invSuff[5] would store 0.  This is used to get next 
        // suffix string from suffix array. 
        static T_UNSIGNED_INT invSuff[T_N];

        // Fill values in invSuff[] 
        for (T_UNSIGNED_INT i = 0; i < n; ++i)
            invSuff[suffixArr[i]] = i;

        // Initialize length of previous LCP 
        T_UNSIGNED_INT k = 0;

        // Process all suffixes one by one starting from 
        // first suffix in txt[] 
        for (T_UNSIGNED_INT i = 0; i < n; ++i)
        {
            /* If the current suffix is at n-1, then we don’t
               have next substring to consider. So lcp is not
               defined for this substring, we put zero. */
            if (invSuff[i] == n - 1)
            {
                k = 0;
                continue;
            }

            /* j contains index of the next substring to
               be considered  to compare with the present
               substring, i.e., next string in suffix array */
            T_UNSIGNED_INT j = suffixArr[invSuff[i] + 1];

            // Directly start matching from k'th index as 
            // at-least k-1 characters will match 
            while (i + k < n && j + k < n && txt[i + k] == txt[j + k])
                k++;

            dst[invSuff[i]] = k; // lcp for the present suffix. 

            // Deleting the starting character from the string. 
            if (k > 0)
                k--;
        }
    }

};

template<typename T_INT, typename T_UNSIGNED_INT, T_UNSIGNED_INT T_N> struct SuffixArraySubstring : public SuffixArray<T_INT, T_UNSIGNED_INT, T_N>
{
    static T_UNSIGNED_INT distinctSubstringCount(const string& txt, SuffixArray<T_INT, T_UNSIGNED_INT, T_N>::Array& array)
    {
        SuffixArray<T_INT, T_UNSIGNED_INT, T_N>::build(txt, array);
        return distinctSubstringCount(array.suffix, array.lcp, static_cast<T_UNSIGNED_INT>(txt.size()));
    }

    static T_UNSIGNED_INT distinctSubstringCount(T_UNSIGNED_INT(&suffix)[T_N], T_UNSIGNED_INT(&lcp)[T_N], T_UNSIGNED_INT n)
    {
        if (n == 0)
            return 0;
        else
        {
            T_UNSIGNED_INT cnt(1); // empty string
            cnt += n - suffix[0]; // first string
            for (T_UNSIGNED_INT i = 1; i < n; ++i)
                cnt += (n - suffix[i]) - lcp[i - 1]; // substring

            return cnt;
        }
    }

    static void print(const string& txt, SuffixArray<T_INT, T_UNSIGNED_INT, T_N>::Array& array)
    {
        print(txt, array.suffix, array.lcp, static_cast<T_UNSIGNED_INT>(txt.size()));
    }

    static void print(const string& txt, T_UNSIGNED_INT(&suffix)[T_N], T_UNSIGNED_INT(&lcp)[T_N], T_UNSIGNED_INT n)
    {
        cout << "str:" << endl;
        cout << txt << endl;

        cout << "Suffix Array:" << endl;
        cout << vector<T_UNSIGNED_INT>(begin(suffix), begin(suffix) + n) << endl;

        cout << "LCP Array:" << endl;
        cout << vector<T_UNSIGNED_INT>(begin(lcp), begin(lcp) + n) << endl;
    }
};

template<typename T> ostream& operator<<(std::ostream& os, const vector<T>& o)
{
    cout << "[";
    if (o.size() > 0)
        cout << o[0];

    for (T i = 1; i < o.size(); ++i)
        cout << "," << o[i];

    cout << "]";

    return os;
}

template<typename T> T read()
{
    T n;
    cin >> n;
    return n;
}

template<typename T> void read(T& obj)
{
    cin >> obj;
}

void readTestcases(unsigned long T)
{
    for (unsigned long i = 0; i < T; ++i)
        compute(Input());
}

void compute(const Input& in)
{
    compute(in.s);
}

typedef SuffixArraySubstring<char, unsigned short, 100> SAS;

void compute(const string& s)
{
    static SAS::Array array;

    const unsigned long res(SAS::distinctSubstringCount(s, array));
    SAS::print(s, array);

    cout << "Distinct Substring Count:" << endl;
    cout << res << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    readTestcases(read<unsigned long>());

    return 0;
}
