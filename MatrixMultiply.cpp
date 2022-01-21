#include <vector>
#include <iostream>

using namespace std;

int MatrixMultiply(vector<vector<int>>& m1, vector<vector<int>>& m2, vector<vector<int>>& ans) {
    ans.clear();
    if (m1.empty() && m2.empty()) return 0;
    if (m1.empty() || m2.empty() || m1[0].size() != m2.size()) {
        return -1;
    }

    int m = m1.size();
    int n = m2[0].size();
    int t = m2.size();
    ans.resize(m, vector<int>(n, 0));
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < t; k++) {
                ans[i][j] += m1[i][k] * m2[k][j];
            }
        }
    }

    return 0;
}

int main()
{
    vector<vector<int>> m1{ {1, 2}, {2, 3} };
    vector<vector<int>> m2{ {1, 4}, {4, 5} };

    vector<vector<int>> rets;
    int ret = MatrixMultiply(m1, m2, rets);
    if (ret) cout << "failed";
    else {
        for (auto& row : rets) {
            for (auto x : row) {
                cout << x << " ";
            }
            cout << endl;
        }
    }

    return 0;
}