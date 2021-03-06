#include <iostream>  // cout
#include <utility>   // pair
#include <numeric>   // accumulate
#include <algorithm> // for_each


using namespace std;


#define __DEBUG__

#ifdef __DEBUG__
#include <cassert>   // assert
#define ASSERT(expr) assert(expr);
#else
#define ASSERT(expr)
#endif


struct Qry
{
    Qry() : L(0), R(0), pos(0) {}
    Qry(unsigned long L, unsigned long R, unsigned long pos, [[maybe_unused]] unsigned long N) : L(L), R(R), pos(pos) { ASSERT(0 <= L && L <= R && R < N); }

    unsigned long L, R, pos;
};

template<size_t MAX_N, size_t MAX_Q, typename T, class T_ADD> static void computeNaive(const unsigned long(&a)[MAX_N], [[maybe_unused]] unsigned long N, const pair<unsigned long, unsigned long>(&q)[MAX_Q], unsigned long Q, T(&r)[MAX_Q], T_ADD add)
{

    for (unsigned long i = 0; i < Q; ++i)
    {
        Qry qry(q[i].first, q[i].second, i, N);
        r[i] = accumulate(a + qry.L + 1, a + qry.R + 1, a[qry.L], add);
    }
}

////////////////////////////////////////////////////////////////
//
// Query Square Root Decomposition (also known as MO's lgorithm)
//
// https://www.geeksforgeeks.org/mos-algorithm-query-square-root-decomposition-set-1-introduction/
// 
////////////////////////////////////////////////////////////////
template<size_t MAX_N, size_t MAX_Q, typename T, class T_ADD, class T_SUB> static void computeQSRD(const unsigned long(&a)[MAX_N], unsigned long N, const pair<unsigned long, unsigned long>(&q)[MAX_Q], unsigned long Q, T(&r)[MAX_Q], T_ADD add, T_SUB sub)
{
    struct Assert
    {
        static bool isValide(unsigned long currL, unsigned long L, unsigned long currR, unsigned long R, unsigned long currSum, const unsigned long(&a)[MAX_N], T_ADD add)
        {
            return currL == L && currR == R && currSum == accumulate(a + L + 1, a + R + 1, a[L], add);
        }
    };

    ASSERT(N > 0);

    // Find block size 
    const unsigned long block(static_cast<unsigned long>(lround(sqrt(N))));

    // Sort all queries so that queries of same blocks 
    // are arranged together. 

    static Qry qry[MAX_Q];
    for (unsigned long i = 0; i < Q; ++i)
        qry[i] = Qry(q[i].first, q[i].second, i, N);
    
    sort(qry, qry + Q, [block](const Qry& x, const Qry& y)
        {
            const unsigned long xLB = x.L / block, yLB = y.L / block;

            return xLB != yLB ? xLB < yLB : x.R < y.R;
        });

    unsigned long currL = 0, currR = 0;
    T currSum = a[0];
    ASSERT(Assert::isValide(currL, 0, currR, 0, currSum, a, add));

    for (unsigned long i = 0; i < Q; i++)
    {
        const unsigned long L = qry[i].L, R = qry[i].R;

        while (currR < R)
        {
            ++currR;
            currSum = add(currSum,a[currR]);
        }

        while (currL < L)
        {
            ASSERT(currSum >= a[currL]);
            currSum = sub(currSum, a[currL]);
            ++currL;
        }
    
        while (currL > L)
        {
            --currL;
            currSum = add(currSum, a[currL]);
        }
    
        while (currR > R)
        {
            ASSERT(currSum >= a[currR]);
            currSum = sub(currSum, a[currR]);
            --currR;
        }

        ASSERT(Assert::isValide(currL, L, currR, R, currSum, a, add));
    
        r[qry[i].pos] = currSum;
    }
}

template<size_t N> ostream& operator<<(ostream& os, const unsigned long (&obj)[N])
{
    os << "[" << obj[0];

    for_each(obj+1, obj+N, [&os](unsigned long x) { os << "," << x; });

    os << "]";

    return os;
}

int main()
{
    const unsigned long a[9] = { 1, 1, 2, 1, 3, 4, 5, 2, 8 };
    const pair<unsigned long, unsigned long> q[3] = { {0, 4}, {1, 3}, {2, 4} };
    unsigned long r1[3], r2[3];

    auto add = [](unsigned long a, unsigned long b) { return a + b; };
    auto sub = [](unsigned long a, unsigned long b) { return a - b; };

    computeNaive(a, 9, q, 3, r1, add);
    computeQSRD(a, 9, q, 3, r2, add, sub);

    ASSERT(equal(r1, r1 + 3, r2));

    cout << r1 << endl;

    return 0;
}
