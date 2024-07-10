#include <iostream>
#include <vector>
#include <string>

using namespace std;

// отвратительная complexity
// нахуй я дышу
class Solution {
    vector<vector<string>> result;

public:
    // Function to copy a matrix
    vector<vector<string>> copyMatrix(const vector<vector<string>>& original) {
        int n = original.size();
        vector<vector<string>> copied(n, vector<string>(n, "0"));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                copied[i][j] = original[i][j];
            }
        }
        return copied;
    }

    // Recursive function to solve N-Queens problem
    void recur(int n, vector<vector<string>>& matrix) {
        if (n == 0) {
            // Convert the matrix to the desired format (replace 'E' with '.')
            vector<string> tmp;
            for (int i = 0; i < matrix.size(); ++i) {
                string str = "";
                for (int j = 0; j < matrix.size(); ++j) {
                    if (matrix[i][j] == "E") {
                        str.append(".");
                    }
                    else {
                        str.append("Q");
                    }
                }
                tmp.push_back(str);
            }
            result.push_back(tmp);
            return;
        }

        for (int col = 0; col < matrix.size(); ++col) {
            if (matrix[n - 1][col] == "0") {
                // Create a copy of the matrix
                vector<vector<string>> tmpMatrix = copyMatrix(matrix);
                tmpMatrix[n - 1][col] = "Q";

                // Mark the attacking positions ('E')
                for (int i = 0; i < matrix.size(); ++i) {
                    if (tmpMatrix[i][col] == "0") tmpMatrix[i][col] = "E";  // Vertical
                    if (tmpMatrix[n - 1][i] == "0") tmpMatrix[n - 1][i] = "E";  // Horizontal
                    int diag1 = n - 1 - i;
                    int diag2 = n - 1 + i;
                    if (diag1 >= 0 && diag1 < matrix.size() && col - i >= 0 && col - i < matrix.size() && tmpMatrix[diag1][col - i] == "0") tmpMatrix[diag1][col - i] = "E";  // Diagonal
                    if (diag2 >= 0 && diag2 < matrix.size() && col - i >= 0 && col - i < matrix.size() && tmpMatrix[diag2][col - i] == "0") tmpMatrix[diag2][col - i] = "E";  // Anti-Diagonal
                    if (diag1 >= 0 && diag1 < matrix.size() && col + i >= 0 && col + i < matrix.size() && tmpMatrix[diag1][col + i] == "0") tmpMatrix[diag1][col + i] = "E";  // Anti-Diagonal
                    if (diag2 >= 0 && diag2 < matrix.size() && col + i >= 0 && col + i < matrix.size() && tmpMatrix[diag2][col + i] == "0") tmpMatrix[diag2][col + i] = "E";  // Anti-Diagonal
                }

                // Recur with reduced N
                recur(n - 1, tmpMatrix);
            }
        }
    }

    // Function to solve N-Queens problem and return all solutions
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> matrix(n, vector<string>(n, "0"));
        recur(n, matrix);
        return result;
    }
};

int main() {
    Solution s;
    vector<vector<string>> result = s.solveNQueens(4);

    // Output all solutions
    for (auto& sol : result) {
        for (auto& row : sol) {
            cout << row << endl;
        }
        cout << endl;
    }

    return 0;
}
