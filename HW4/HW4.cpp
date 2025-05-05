#include <iostream>
using namespace std;

class TicTacToe {
private:
    char board[9];  // 存放 9 格棋盤
    int currentPlayer;  // 1: 玩家 X, 2: 玩家 O

public:
    TicTacToe() {
        resetBoard();
        currentPlayer = 1;
    }

    void resetBoard() {
        for (int i = 0; i < 9; ++i) {
            board[i] = '1' + i;
        }
    }

    void displayBoard() {
        cout << "-- Tic Tac Toe -- CSIE@CGU\n";
        cout << "Player 1 (X)  -  Player 2 (O)\n\n";
        for (int i = 0; i < 9; i += 3) {
            cout << " " << board[i] << " | " << board[i+1] << " | " << board[i+2] << "\n";
            if (i < 6) cout << "---+---+---\n";
        }
        cout << endl;
    }

    bool makeMove(int pos) {
        if (pos < 1 || pos > 9) return false;
        if (board[pos - 1] == 'X' || board[pos - 1] == 'O') return false;
        board[pos - 1] = (currentPlayer == 1) ? 'X' : 'O';
        return true;
    }

    bool checkWin() {
        const int wins[8][3] = {
            {0,1,2},{3,4,5},{6,7,8},
            {0,3,6},{1,4,7},{2,5,8},
            {0,4,8},{2,4,6}
        };
        char symbol = (currentPlayer == 1) ? 'X' : 'O';
        for (int i = 0; i < 8; ++i) {
            if (board[wins[i][0]] == symbol &&
                board[wins[i][1]] == symbol &&
                board[wins[i][2]] == symbol) {
                return true;
            }
        }
        return false;
    }

    bool isDraw() {
        for (int i = 0; i < 9; ++i) {
            if (board[i] != 'X' && board[i] != 'O') return false;
        }
        return true;
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer == 1) ? 2 : 1;
    }

    void play() {
        int move;
        while (true) {
            displayBoard();
            cout << "Player " << currentPlayer << ", 請輸入 [1~9] 的數字：";
            cin >> move;

            if (!cin) {
                cin.clear(); // 清除錯誤旗標
                cin.ignore(1000, '\n'); // 忽略輸入列
                cout << "輸入錯誤，請重新輸入下一步\n\n";
                continue;
            }

            if (!makeMove(move)) {
                cout << "請重新輸入下一步\n\n";
                continue;
            }

            if (checkWin()) {
                displayBoard();
                cout << "==>Player " << currentPlayer << " win\n";
                break;
            }

            if (isDraw()) {
                displayBoard();
                cout << "==>Game draw\n";
                break;
            }

            switchPlayer();
        }
    }
};
... (還剩 6 行)
收起
message.txt
3 KB
﻿
I am a coconut!
monkeyovo
monkeyovo
 
 
#include <iostream>
using namespace std;

class TicTacToe {
private:
    char board[9];  // 存放 9 格棋盤
    int currentPlayer;  // 1: 玩家 X, 2: 玩家 O

public:
    TicTacToe() {
        resetBoard();
        currentPlayer = 1;
    }

    void resetBoard() {
        for (int i = 0; i < 9; ++i) {
            board[i] = '1' + i;
        }
    }

    void displayBoard() {
        cout << "-- Tic Tac Toe -- CSIE@CGU\n";
        cout << "Player 1 (X)  -  Player 2 (O)\n\n";
        for (int i = 0; i < 9; i += 3) {
            cout << " " << board[i] << " | " << board[i+1] << " | " << board[i+2] << "\n";
            if (i < 6) cout << "---+---+---\n";
        }
        cout << endl;
    }

    bool makeMove(int pos) {
        if (pos < 1 || pos > 9) return false;
        if (board[pos - 1] == 'X' || board[pos - 1] == 'O') return false;
        board[pos - 1] = (currentPlayer == 1) ? 'X' : 'O';
        return true;
    }

    bool checkWin() {
        const int wins[8][3] = {
            {0,1,2},{3,4,5},{6,7,8},
            {0,3,6},{1,4,7},{2,5,8},
            {0,4,8},{2,4,6}
        };
        char symbol = (currentPlayer == 1) ? 'X' : 'O';
        for (int i = 0; i < 8; ++i) {
            if (board[wins[i][0]] == symbol &&
                board[wins[i][1]] == symbol &&
                board[wins[i][2]] == symbol) {
                return true;
            }
        }
        return false;
    }

    bool isDraw() {
        for (int i = 0; i < 9; ++i) {
            if (board[i] != 'X' && board[i] != 'O') return false;
        }
        return true;
    }

    void switchPlayer() {
        currentPlayer = (currentPlayer == 1) ? 2 : 1;
    }

    void play() {
        int move;
        while (true) {
            displayBoard();
            cout << "Player " << currentPlayer << ", 請輸入 [1~9] 的數字：";
            cin >> move;

            if (!cin) {
                cin.clear(); // 清除錯誤旗標
                cin.ignore(1000, '\n'); // 忽略輸入列
                cout << "輸入錯誤，請重新輸入下一步\n\n";
                continue;
            }

            if (!makeMove(move)) {
                cout << "請重新輸入下一步\n\n";
                continue;
            }

            if (checkWin()) {
                displayBoard();
                cout << "==>Player " << currentPlayer << " win\n";
                break;
            }

            if (isDraw()) {
                displayBoard();
                cout << "==>Game draw\n";
                break;
            }

            switchPlayer();
        }
    }
};

int main() {
    TicTacToe game;
    game.play();
    return 0;
}