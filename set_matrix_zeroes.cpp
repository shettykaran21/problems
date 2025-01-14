#include <bits/stdc++.h>

using namespace std;

void printMatrix(vector<vector<int>> &v) {
    int m = v.size(), n = v[0].size();

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            cout << v[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "\n";
}

void setColZero(vector<vector<int>> &v, int colIndex) {
    int rows = v.size();

    for (int i = 0; i < rows; ++i) {
        v[i][colIndex] = 0;
    }
}

void setRowZero(vector<vector<int>> &v, int rowIndex) {
    int cols = v[0].size();

    for (int i = 0; i < cols; ++i) {
        v[rowIndex][i] = 0;
    }
}

/*
    Create temp matrix, iterate through temp matrix and make changes in original matrix
    O(m*n) * (O(m) + O(n)) time
    O(m*n) space
*/
void solve_1(vector<vector<int>> &v) {
    int m = v.size(), n = v[0].size();

    vector<vector<int>> temp(v);

    for (int i = 0; i < m; ++i) {  // O(m*n)
        for (int j = 0; j < n; ++j) {
            if (temp[i][j] == 0) {
                setRowZero(v, i);  // O(m)
                setColZero(v, j);  // O(n)
            }
        }
    }
}

void markRow(vector<vector<int>> &v, int rowIndex) {
    int cols = v[0].size();

    for (int i = 0; i < cols; ++i) {
        if (v[rowIndex][i] != 0) {
            v[rowIndex][i] = -1;
        }
    }
}

void markCol(vector<vector<int>> &v, int colIndex) {
    int rows = v.size();

    for (int i = 0; i < rows; ++i) {
        if (v[i][colIndex] != 0) {
            v[i][colIndex] = -1;
        }
    }
}

/*
    Instead of creating a new matrix, mark in the same matrix with something unique (eg. -1)
    Later, replace -1 with 0s
    Time - O(m*n) * (O(m) + O(n))
    Space - O(1)
*/
void solve_2(vector<vector<int>> &v) {
    int m = v.size(), n = v[0].size();

    for (int i = 0; i < m; ++i) {  // O(m*n)
        for (int j = 0; j < n; ++j) {
            if (v[i][j] == 0) {
                markRow(v, i);  // O(m)
                markCol(v, j);  // O(n)
            }
        }
    }

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (v[i][j] == -1) {
                v[i][j] = 0;
            }
        }
    }
}

/*
    Create two vectors, one to keep track of which row has to be 0, and another to keep track of which column has to be 0
    Iterate, and mark the indices as 0
    Iterate through the matrix again and set the row to 0, if hashCol[i] = 0, set the column to 0 if hashRow[i] = 0
    Time - O(m*n)
    Space - O(m) + O(n)
*/
void solve_3(vector<vector<int>> &v) {
    int m = v.size(), n = v[0].size();

    vector<int> hashRow(n, -1);
    vector<int> hashCol(m, -1);

    for (int i = 0; i < m; ++i) {  // O(m*n)
        for (int j = 0; j < n; ++j) {
            if (v[i][j] == 0) {
                hashRow[j] = 0;  // O(1)
                hashCol[i] = 0;  // O(1)
            }
        }
    }

    for (int i = 0; i < m; ++i) {  // O(m*n)
        for (int j = 0; j < n; ++j) {
            if (hashRow[j] == 0 || hashCol[i] == 0) {
                v[i][j] = 0;
            }
        }
    }
}

/*
    Instead of using extra space for hash arrays, treat 1st row and 1st column as hash arrays
    Time - O(m*n)
    Space - O(1)
*/
void solve_4(vector<vector<int>> &v) {
    int m = v.size(), n = v[0].size();

    int row0 = -1;

    for (int i = 0; i < m; ++i) {
        for (int j = 0; j < n; ++j) {
            if (v[i][j] == 0) {
                // For first column, mark row0 as 0
                if (j == 0) {
                    row0 = 0;
                    continue;
                }

                v[i][0] = 0;
                v[0][j] = 0;
            }
        }
    }

    // First update values other than hash ones
    for (int i = 1; i < m; ++i) {
        for (int j = 1; j < n; ++j) {
            if (v[i][0] == 0 || v[0][j] == 0) {
                v[i][j] = 0;
            }
        }
    }

    // Then update hash row. Hash col cannot be updated first as hash row values depends on first value hash col
    if (v[0][0] == 0) {
        for (int i = 0; i < n; ++i) {
            v[0][i] = 0;
        }
    }

    // Then hash col
    if (row0 == 0) {
        for (int i = 0; i < m; ++i) {
            v[i][0] = 0;
        }
    }
}

int main() {
    vector<vector<int>> v = {{0, 1, 2, 0},
                             {3, 4, 5, 2},
                             {1, 3, 0, 5}};

    printMatrix(v);

    solve_4(v);

    printMatrix(v);

    return 0;
}