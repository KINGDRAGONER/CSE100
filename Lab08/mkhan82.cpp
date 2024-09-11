#include <iostream>
#include <vector>

using namespace std;
int inf = 2147483647;
int neginf= -2147483648;
//  Find the minimum number of scalar mult and print the sequence
void matrixChainOrder(const vector<int>& p, int& mscalmult, vector<vector<int>>& m, vector<vector<int>>& s) {
    int n = p.size() - 1;

    // Initialize m matrix with zeros and s matrix with -1 for the base cases
    for (int i = 1; i <= n; i++) {
        m[i][i] = 0;
        s[i][i] = -1;
    }

    for (int chainLength = 2; chainLength <= n; chainLength++) {
        for (int i = 1; i <= n - chainLength + 1; i++) {
            int j = i + chainLength - 1; //define j as j i+l- 1
            m[i][j] =  inf; //max int for 32 bit for just a high positve number or infitity

            for (int k = i; k < j; k++) {
                int q = m[i][k] + m[k + 1][j] + p[i - 1] * p[k] * p[j];//q = m[i, k] + m|k + 1, j] + pi-1PkP;
                if (q < m[i][j]) {
                    m[i][j] = q;
                    s[i][j] = k;
                }
            }
        }
    }

    mscalmult = m[1][n];
}

void printOptimalParens(const vector<vector<int>>& s, int i, int j) {
    if (i == j) {
        cout << "A" << i - 1;
    } else {
        cout << "(";
        printOptimalParens(s, i, s[i][j]);
        printOptimalParens(s, s[i][j] + 1, j);
        cout << ")";
    }
}
//let m 1..n, 1..n and s1..n - 1,2..n be new tables
void allocationmatrix(int n, std::vector<int>& p, std::vector<std::vector<int>>& m, std::vector<std::vector<int>>& s){
    p.resize(n + 1);
    for (int i = 0; i <= n; i++) {
        cin >> p[i];
    }

    m.resize(n + 1, std::vector<int>(n + 1));//resizes the 2D vector m to have dimensions (n + 1) x (n + 1)
    s.resize(n + 1, std::vector<int>(n + 1));//resizes the 2D vector n to have dimensions (n + 1) x (n + 1)
}
int main() {
    int n;
    cin >> n;
    std::vector<int> p;
    std::vector<std::vector<int>> m, s;
    allocationmatrix(n, p, m, s);
    int temp;
    matrixChainOrder(p, temp, m, s);

    cout << temp << endl;
    printOptimalParens(s, 1, n);
    cout << endl;

    return 0;
}
