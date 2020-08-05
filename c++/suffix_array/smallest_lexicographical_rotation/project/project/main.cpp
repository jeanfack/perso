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
template<typename T_TYPE, typename T_SIZE> struct SuffixArray;
template<typename T_TYPE, typename T_SIZE> struct SuffixArrayRotate;

/////////////////////////////
//
// declaration function
//
/////////////////////////////
template<typename T_TYPE, typename T_SIZE> ostream& operator<<(std::ostream& os, const SuffixArray<T_TYPE, T_SIZE>& o);
template<typename T_SIZE> ostream& operator<<(std::ostream& os, const vector<T_SIZE>& o);
template<typename T_TYPE, typename T_SIZE> ostream& operator<<(std::ostream& os, const SuffixArrayRotate<T_TYPE, T_SIZE>& o);
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

template<typename T_TYPE, typename T_SIZE> struct SuffixArray
{
    struct Suffix
    {
        Suffix() : index(0), rank{0,0}
        {
        }

        T_SIZE index;  // To store original index 
        T_TYPE rank[2]; // To store ranks and next rank pair 
    };

    SuffixArray(const string& s) : txt(s), suffix(buildSuffix(s)), lcp(buildLcp(s, suffix))
    {
    }

    const string txt;
    const vector<T_SIZE> suffix;
    const vector<T_SIZE> lcp;

    static bool cmp(Suffix& a, Suffix& b)
    {
        return (a.rank[0] == b.rank[0]) ? (a.rank[1] < b.rank[1] ? true : false) :
            (a.rank[0] < b.rank[0] ? true : false);
    }

    static vector<T_SIZE> buildSuffix(const string& txt)
    {
        return buildSuffix(txt, txt.size());
    }

        // This is the main function that takes a string 'txt' of size n as an 
    // argument, builds and return the suffix array for the given string 
    static vector<T_SIZE> buildSuffix(const string& txt, T_SIZE n)
    {
        // A structure to store suffixes and their indexes 
        vector<Suffix> suffixes(n);

        // Store suffixes and their indexes in an array of structures. 
        // The structure is needed to sort the suffixes alphabatically 
        // and maintain their old indexes while sorting 
        for (T_SIZE i = 0; i < n; i++)
        {
            suffixes[i].index = i;
            suffixes[i].rank[0] = txt[i] - 'a';
            suffixes[i].rank[1] = ((i + 1) < n) ? (txt[i + 1] - 'a') : -1;
        }

        // Sort the suffixes using the comparison function 
        // defined above. 
        sort(suffixes.begin(), suffixes.begin() + n, cmp);

        // At his point, all suffixes are sorted according to first 
        // 2 characters.  Let us sort suffixes according to first 4 
        // characters, then first 8 and so on 
        vector<T_SIZE> ind(n, 0);  // This array is needed to get the index in suffixes[] 
        // from original index.  This mapping is needed to get 
        // next suffix. 
        for (T_SIZE k = 4; k < 2 * n; k = k * 2)
        {
            // Assigning rank and index values to first suffix 
            T_TYPE rank = 0;
            T_TYPE prev_rank = suffixes[0].rank[0];
            suffixes[0].rank[0] = rank;
            ind[suffixes[0].index] = 0;

            // Assigning rank to suffixes 
            for (T_SIZE i = 1; i < n; i++)
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
            for (T_SIZE i = 0; i < n; i++)
            {
                T_SIZE nextindex = suffixes[i].index + k / 2;
                suffixes[i].rank[1] = (nextindex < n) ?
                    suffixes[ind[nextindex]].rank[0] : -1;
            }

            // Sort the suffixes according to first k characters 
            sort(suffixes.begin(), suffixes.begin() + n, cmp);
        }

        // Store indexes of all sorted suffixes in the suffix array 
        vector<T_SIZE>suffixArr;
        for (T_SIZE i = 0; i < n; i++)
            suffixArr.push_back(suffixes[i].index);

        // Return the suffix array 
        return  suffixArr;
    }

    static vector<T_SIZE> buildLcp(const string& txt, vector<T_SIZE> suffixArr)
    {
        return buildLcp(txt, suffixArr, txt.size());
    }

    /* To construct and return LCP using kasai Algorithm */
    static vector<T_SIZE> buildLcp(const string& txt, vector<T_SIZE> suffixArr, T_SIZE n)
    {
        // To store LCP array 
        vector<T_SIZE> lcp(n, 0);

        // An auxiliary array to store inverse of suffix array 
        // elements. For example if suffixArr[0] is 5, the 
        // invSuff[5] would store 0.  This is used to get next 
        // suffix string from suffix array. 
        vector<T_SIZE> invSuff(n, 0);

        // Fill values in invSuff[] 
        for (T_SIZE i = 0; i < n; i++)
            invSuff[suffixArr[i]] = i;

        // Initialize length of previous LCP 
        int k = 0;

        // Process all suffixes one by one starting from 
        // first suffix in txt[] 
        for (T_SIZE i = 0; i < n; i++)
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
            T_SIZE j = suffixArr[invSuff[i] + 1];

            // Directly start matching from k'th index as 
            // at-least k-1 characters will match 
            while (i + k < n && j + k < n && txt[i + k] == txt[j + k])
                k++;

            lcp[invSuff[i]] = k; // lcp for the present suffix. 

            // Deleting the starting character from the string. 
            if (k > 0)
                k--;
        }

        // return the constructed lcp array 
        return lcp;
    }

};

template<typename T_TYPE, typename T_SIZE> struct SuffixArrayRotate
{
    SuffixArrayRotate(const string& txt) : data(string(txt).append(txt))
    {
    }

    T_SIZE SmallestLexicographicalRotationIdx() const
    {
        return SuffixArrayRotate::SmallestLexicographicalRotationIdx(data.suffix, data.suffix.size.size());
    }

    static T_SIZE SmallestLexicographicalRotationIdx(const vector<T_SIZE>& suffix, T_SIZE n)
    {
        T_SIZE i = 0;
        for (; i < n; ++i)
            if (suffix[i] < n / 2)
                break;

        return suffix[i];
    }

    const string SmallestLexicographicalRotationString() const
    {
        return SuffixArrayRotate::SmallestLexicographicalRotationString(data.txt, data.suffix, data.txt.size());
    }

    static const string SmallestLexicographicalRotationString(const string& txt, const vector<T_SIZE>& suffix, T_SIZE n)
    {
        return SmallestLexicographicalRotationString(txt, SmallestLexicographicalRotationIdx(suffix, n), n);
    }

    static const string SmallestLexicographicalRotationString(const string& txt, T_SIZE idx, T_SIZE n)
    {
        return string(txt, idx, n / 2);
    }


    const SuffixArray<T_TYPE, T_SIZE> data;
};

/////////////////////////////
//
// definition function
//
/////////////////////////////
template<typename T_TYPE, typename T_SIZE> ostream& operator<<(std::ostream& os, const SuffixArray<T_TYPE, T_SIZE>& o)
{
    cout << "str:" << endl;
    cout << o.txt << endl;

    cout << "Suffix Array:" << endl;
    cout << o.suffix << endl;

    cout << "LCP Array:" << endl;
    cout << o.lcp << endl;

    return os;
}

template<typename T_SIZE> ostream& operator<<(std::ostream& os, const vector<T_SIZE>& o)
{
    cout << "[";
    if (o.size() > 0)
        cout << o[0];

    for (T_SIZE i = 1; i < o.size(); ++i)
        cout << "," << o[i];

    cout << "]" << endl;

    return os;
}

template<typename T_TYPE, typename T_SIZE> ostream& operator<<(std::ostream& os, const SuffixArrayRotate<T_TYPE, T_SIZE>& o)
{
    cout << o.data << endl;

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

void compute(const string& s)
{
    SuffixArray<long, unsigned long> suffixArray(s);
    cout << suffixArray << endl;

    SuffixArrayRotate<long, unsigned long> suffixArrayRotate(s);
    cout << suffixArrayRotate << endl;

    cout << "Smallest lexicographical rotation:" << endl;
    cout << suffixArrayRotate.SmallestLexicographicalRotationString() << endl;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);

    readTestcases(read<unsigned long>());

    return 0;
}
