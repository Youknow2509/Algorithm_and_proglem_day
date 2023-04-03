#include <iostream>
#include <vector>
using namespace std;

const int n = 9;

// Kiểm tra số đã được điền vào ô vuông 3x3 có hợp lệ hay không
bool checkSquare(int row, int col, char num, vector<string>& board) {
    int rowStart = (row / 3) * 3;
    int colStart = (col / 3) * 3;
    for (int i = rowStart; i < rowStart + 3; i++) {
        for (int j = colStart; j < colStart + 3; j++) {
            if (board[i][j] == num) {
                return false;
            }
        }
    }
    return true;
}

// Kiểm tra số đã được điền vào hàng và cột có hợp lệ hay không
bool checkRowAndCol(int row, int col, char num, vector<string>& board) {
    for (int i = 0; i < n; i++) {
        if (board[row][i] == num || board[i][col] == num) {
            return false;
        }
    }
    return true;
}

// Hàm giải quyết bài toán Sudoku bằng thuật toán quay lui
bool solveSudoku(vector<string>& board) {
    for (int row = 0; row < n; row++) {
        for (int col = 0; col < n; col++) {
            if (board[row][col] == '0') {
                for (char num = '1'; num <= '9'; num++) {
                    if (checkRowAndCol(row, col, num, board) && checkSquare(row, col, num, board)) {
                        board[row][col] = num;
                        if (solveSudoku(board)) {
                            return true;
                        }
                        board[row][col] = '0';
                    }
                }
                return false;
            }
        }
    }
    return true;
}

// Hàm in ra bảng Sudoku
void printSudoku(vector<string>& board) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << board[i][j] << " ";
        }
        cout << endl;
    }
}

vector<string> sudokuSolve(vector<string> matrix) {
    solveSudoku(matrix);
    return matrix;
}

int main() {
    vector<string> board = {"530070000", "600195000", "098000060", "800060003", "400803001
