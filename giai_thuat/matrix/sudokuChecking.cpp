#include <iostream>
#include <vector>

using namespace std;

const int N = 9; // Kích thước của bảng Sudoku

// Hàm kiểm tra tính hợp lệ của một hàng
bool isValidRow(std::vector<std::vector<char>> board, int row) {
    bool used[9] = {false};
    for (int i = 0; i < 9; i++) {
        if (board[row][i] != '.'){
            int num = board[row][i] - '0';
            if (used[num-1]) {
                    return false;
            }
            used[num-1] = true;
        }
    }
    return true;
}

// Hàm kiểm tra tính hợp lệ của một cột
bool isValidCol(std::vector<std::vector<char>> board, int col) {
    bool used[9] = {false};
    for (int i = 0; i < 9; i++) {
        if (board[i][col] != '.'){
            int num = board[i][col] - '0';
            if (used[num-1]) {
                    return false;
            }
            used[num-1] = true;
        }
    }
    return true;
}

// Hàm kiểm tra tính hợp lệ của một bảng con 3x3
bool isValidBox(std::vector<std::vector<char>> board, int startRow, int startCol) {
    bool used[9] = {false};
    for (int i = startRow; i < startRow+3; i++) {
        for (int j = startCol; j < startCol+3; j++) {
            if (board[i][j] != '.'){
            int num = board[i][j] - '0';
            if (used[num-1]) {
                    return false;
            }
            used[num-1] = true;
        }
        }
    }
    return true;
}

// Hàm kiểm tra tính hợp lệ của toàn bộ bảng Sudoku
bool sudokuChecking(std::vector<std::vector<char>> board) {
    // Kiểm tra tính hợp lệ của từng hàng và cột
    for (int i = 0; i < 9; i++) {
        if (!isValidRow(board, i) || !isValidCol(board, i)) {
            return false;
        }
    }
    // Kiểm tra tính hợp lệ của từng bảng con 3x3
    for (int i = 0; i < 9; i += 3) {
        for (int j = 0; j < 9; j += 3) {
            if (!isValidBox(board, i, j)) {
                return false;
            }
        }
    }
    return true;
}

// Hàm main để kiểm tra kết quả
int main() {

}
