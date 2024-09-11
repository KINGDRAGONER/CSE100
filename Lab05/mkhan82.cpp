#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
// Counting Sort function
// Time complexity: O(n + k)
void countingSort(vector<vector<int> > &A, int digit)
{
    const int k = 4;
    vector<vector<int> > B(A.size(), vector<int>(10));

    vector<int> C(k + 1, 0);

    for (int i = 0; i < A.size(); i++)
    {
        int d = A[i][digit];
        C[d]++;
    }

    for (int i = 1; i <= k; i++)
    {
        C[i] += C[i - 1];
    }

    for (int i = A.size() - 1; i >= 0; i--)
    {
        int d = A[i][digit];
        B[C[d] - 1] = A[i];
        C[d]--;
    }

    A = B;
}

// Time complexity: O(d * (n + k))
void radixSort(vector<vector<int> > &A)
{
    int d = 10;
    // Perform counting sort for each digit from the least significant to the most significant
    for (int i = d - 1; i >= 0; i--)
    {
        countingSort(A, i);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<vector<int> > vectors(n, vector<int>(10));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cin >> vectors[i][j];
        }
    }

    radixSort(vectors);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 10; j++)
        {
            cout << vectors[i][j];
            if (j < 9)
            {
                cout << ";";
            }
        }
        cout << ";" << endl;
    }

    return 0;
}
