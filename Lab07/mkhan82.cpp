#include <iostream>
#include <vector>

using namespace std;
// make prototype functions to later use
int memorizedCutRod(const vector<int> &p, int n, vector<int> &r);
int cutRod(const vector<int> &p, int n);
void printCutRodSolution(const vector<int> &p, int n);
// MEMOIZED-CUT-ROD-AUX (p, n, r)
// 1 ifr|n] ≥ 0
// 2
// return rn]
// 3
// if n == 0
// 4
// 9=0
// 5
// else q
// = —00
// 6
// for i = 1 ton
// q = max(q, p[i] + MEMOIZED-CUT-ROD-AUX(p,n - i,r))
// 8 rIn] = q
// 9 return q
int memorizedCutRod(const vector<int> &p, int n, vector<int> &r)
{
    int q;
    if (r[n] >= 0)
    {
        return r[n];
    }

    if (n == 0)
    {
        q = 0;
    }
    else
    {
        q = -1; // else q = -inf
        for (int i = 1; i <= n; i++)
        {
            q = max(q, p[i] + memorizedCutRod(p, n - i, r));
        }
    }
    r[n] = q;
    return q;
}
// CUT-ROD(p,n)
// 1 if n == 0
// 2
// return 0
// 3
// 9 = -0
// for i = 1 to n
// 5
// q = max(q, pli] + CUT-ROD(p,n - i))
// 6 return q
int cutRod(const vector<int> &p, int n)
{
    vector<int> r(n + 1, -1);

    return memorizedCutRod(p, n, r);
}

void printCutRodSolution(const vector<int> &p, int n)
{
    vector<int> r(n + 1); // Create a memoization table for maximum revenue.
    vector<int> s(n + 1); // Create a table to store optimal cut lengths.

    r[0] = 0; // Base case: Zero revenue for a rod of length zero.

    // Calculate maximum revenue for different rod lengths.
    for (int i = 1; i <= n; i++)
    {
        int maxRevenue = -1;

        // Iterate through possible cut positions and find the optimal one.
        for (int j = 1; j <= i; j++)
        {
            if (p[j] + r[i - j] > maxRevenue)
            {
                maxRevenue = p[j] + r[i - j];
                s[i] = j; // Store the optimal cut position.
            }
        }

        r[i] = maxRevenue; // Memoize the maximum revenue for length i.
    }

    int length = n;

    // Print the optimal cut positions for the rod.
    while (length > 0)
    {
        cout << s[length] << " ";
        length -= s[length];
    }

    cout << -1 << endl; // End of the optimal cut positions.
}

int main()
{
    int n;
    cin >> n;

    vector<int> p(n + 1);
    for (int i = 1; i <= n; i++)
    {
        cin >> p[i];
    }

    int maxRevenue = cutRod(p, n);
    cout << maxRevenue << endl;
    printCutRodSolution(p, n);

    return 0;
}
//worst-case time complexity is O(n^2)
//Ω(n) might not need to explore all possible cuts
//Θ(n^2) because the upper and lower bounds match in this case