#include <iostream>
#include <Windows.h>
#include <vector>
#include <iomanip>
#include <string>
#include <random>
#include <time.h>

using namespace std;

class TicTacToe
{
protected:
	vector<vector<char>> board;
public:
	TicTacToe(int rows = 10, int cols = 10)
	{
		board = vector<vector<char>>(rows, vector<char>(cols, ' '));
	}
protected:
	bool checkWinRows(bool isBlockTwoSides, char& playerWin)
	{
		if (isBlockTwoSides == false)
		{
			for (int i = 0; i < (int)board.size(); i++)
			{
				for (int j = 0; j < (int)board[0].size() - 4; j++)
				{
					if (board[i][j] == board[i][j + 1] && board[i][j] == board[i][j + 2] && board[i][j] == board[i][j + 3] && board[i][j] == board[i][j + 4] && board[i][j] != ' ')
					{
						playerWin = board[i][j];
						return true;
					}
				}
			}
			return false;
		}
		else
		{
			for (int i = 0; i < (int)board.size(); i++)
			{
				for (int j = 0; j < (int)board[0].size() - 4; j++)
				{
					if (board[i][j] == board[i][j + 1] && board[i][j] == board[i][j + 2] && board[i][j] == board[i][j + 3] && board[i][j] == board[i][j + 4] && board[i][j] != ' ')
					{
						if (j == 0 || j == (int)board[0].size() - 5)
						{
							playerWin = board[i][j];
							return true;
						}
						else
						{
							if (board[i][j + 5] != board[i][j - 1])
							{
								playerWin = board[i][j];
								return true;
							}
						}
					}
				}
			}
			return false;
		}
	}
	bool checkWinCols(bool isBlockTwoSides, char& playerWin)
	{
		if (isBlockTwoSides == false)
		{
			for (int i = 0; i < (int)board.size() - 4; i++)
			{
				for (int j = 0; j < (int)board[0].size(); j++)
				{
					if (board[i][j] == board[i + 1][j] && board[i][j] == board[i + 2][j] && board[i][j] == board[i + 3][j] && board[i][j] == board[i + 4][j] && board[i][j] != ' ')
					{
						playerWin = board[i][j];
						return true;
					}
				}
			}
			return false;
		}
		else
		{
			for (int i = 0; i < (int)board.size() - 4; i++)
			{
				for (int j = 0; j < (int)board[0].size(); j++)
				{
					if (board[i][j] == board[i + 1][j] && board[i][j] == board[i + 2][j] && board[i][j] == board[i + 3][j] && board[i][j] == board[i + 4][j] && board[i][j] != ' ')
					{
						if (i == 0 || i == (int)board.size() - 5)
						{
							playerWin = board[i][j];
							return true;
						}
						else
						{
							if (board[i + 5][j] != board[i - 1][j])
							{
								playerWin = board[i][j];
								return true;
							}
						}
					}
				}
			}
			return false;
		}
	}
	bool checkWinLeftDiags(bool isBlockTwoSides, char& playerWin)
	{
		if (isBlockTwoSides == false)
		{
			for (int i = 0; i < (int)board.size() - 4; i++)
			{
				for (int j = 0; j < (int)board[0].size() - 4; j++)
				{
					if (board[i][j] == board[i + 1][j + 1] && board[i][j] == board[i + 2][j + 2] && board[i][j] == board[i + 3][j + 3] && board[i][j] == board[i + 4][j + 4] && board[i][j] != ' ')
					{
						playerWin = board[i][j];
						return true;
					}
				}
			}
			return false;
		}
		else
		{
			for (int i = 0; i < (int)board.size() - 4; i++)
			{
				for (int j = 0; j < (int)board[0].size() - 4; j++)
				{
					if (board[i][j] == board[i + 1][j + 1] && board[i][j] == board[i + 2][j + 2] && board[i][j] == board[i + 3][j + 3] && board[i][j] == board[i + 4][j + 4] && board[i][j] != ' ')
					{
						if (i == 0 || j == 0 || j == (int)board[0].size() - 5 || i == (int)board.size() - 5)
						{
							playerWin = board[i][j];
							return true;
						}
						else
						{
							if (board[i + 5][j + 5] != board[i - 1][j - 1])
							{
								playerWin = board[i][j];
								return true;
							}
						}
					}
				}
			}
			return false;
		}
	}
	bool checkWinRightDiags(bool isBlockTwoSides, char& playerWin)
	{
		if (isBlockTwoSides == false)
		{
			for (int i = (int)board.size() - 5; i >= 0; i--)
			{
				for (int j = (int)board[0].size() - 1; j >= 4; j--)
				{
					if (board[i][j] == board[i + 1][j - 1] && board[i][j] == board[i + 2][j - 2] && board[i][j] == board[i + 3][j - 3] && board[i][j] == board[i + 4][j - 4] && board[i][j] != ' ')
					{
						playerWin = board[i][j];
						return true;
					}
				}
			}
			return false;
		}
		else
		{
			for (int i = (int)board.size() - 5; i >= 0; i--)
			{
				for (int j = (int)board[0].size() - 1; j >= 4; j--)
				{
					if (board[i][j] == board[i + 1][j - 1] && board[i][j] == board[i + 2][j - 2] && board[i][j] == board[i + 3][j - 3] && board[i][j] == board[i + 4][j - 4] && board[i][j] != ' ')
					{
						if (i == 0 || i == (int)board.size() - 5 || j == (int)board[0].size() - 1 || j == (int)board[0].size() - 5)
						{
							playerWin = board[i][j];
							return true;
						}
						else
						{
							if (board[i + 5][j - 5] != board[i - 1][j + 1])
							{
								playerWin = board[i][j];
								return true;
							}
						}
					}
				}
			}
			return false;
		}
	}
public:
	void printBoard()
	{
		cout << "    ";
		for (char x = 'a'; x < (char)((int)'a' + (int)board[0].size()); x++)
		{
			cout << x << " ";
		}
		cout << '\n';
		cout << "    ";
		for (int i = 0; i < (int)board[0].size(); i++)
		{
			cout << "- ";
		}
		cout << '\n';
		for (int i = 0; i < (int)board.size(); i++)
		{
			cout << setw(2) << setfill(' ') << i + 1 << " |";
			for (int j = 0; j < (int)board[0].size(); j++)
			{
				cout << board[i][j] << (j == (int)board[0].size() - 1 ? "|\n" : "|");
			}
			cout << "    ";
			for (int x = 0; x < (int)board[0].size(); x++)
			{
				cout << "- ";
			}
			cout << '\n';
		}
	}
	bool checkValidInput(string s)
	{
		if (!(s[0] >= '0' && s[0] <= '9'))
		{
			return false;
		}
		int N = s.length();
		if (!(s[N - 1] >= 'a' && s[N - 1] <= 'j'))
		{
			return false;
		}
		char c = s[N - 1];
		int M = stoi(s.substr(0, N - 1));
		if (M < 1 || M > 10)
		{
			return false;
		}
		if (board[M - 1][c - 'a'] != ' ')
		{
			return false;
		}
		return true;
	}
	void MakeAMove(string s, bool isFirstPlayer)
	{
		char col = s[s.length() - 1];
		int row = stoi(s.substr(0, s.length() - 1));
		if (isFirstPlayer)
		{
			board[row - 1][col - 'a'] = 'X';
		}
		else
		{
			board[row - 1][col - 'a'] = 'O';
		}
	}
	int checkWin(bool isBlockTwoSides, char& playerWin)
	{
		if (checkWinCols(isBlockTwoSides, playerWin) || checkWinLeftDiags(isBlockTwoSides, playerWin) || checkWinRightDiags(isBlockTwoSides, playerWin) || checkWinRows(isBlockTwoSides, playerWin))
		{
			return 1;
		}
		else
		{
			for (int i = 0; i < (int)board.size(); i++)
			{
				for (int j = 0; j < (int)board[0].size(); j++)
				{
					if (board[i][j] == ' ')
					{
						return -1;
					}
				}
			}
			return 0;
		}
	}
	void startGame()
	{
		cout << "Test game TicTacToe using Class\n";
		int opt;
		bool isBlockTwoSides;
		char playerWin = ' ';
		do
		{
			cout << "Choose tic - tac - toe rules (1 - Normal rules, 2 - Normal rules + block 2 sides rule): ";
			cin >> opt;
		} while (opt < 1 || opt > 2);
		if (opt == 1)
		{
			isBlockTwoSides = false;
		}
		else
		{
			isBlockTwoSides = true;
		}
		cin.ignore();
		cout << "How to play? Input format: rowcol, row from 1 to 10, col from a to j. For example: 9a is a valid input\n";
		cout << "Enter 1st player name: ";
		string fname;
		getline(cin, fname);
		cout << "Enter 2st player name: ";
		string sname;
		getline(cin, sname);
		cout << "Flip the coin (0 is head, 1 is tail): ";
		Sleep(2000);
		int N = rand() % 2;
		cout << N << '\n';
		string recent = (N == 0 ? fname : sname);
		cout << recent << " go first\n";
		Sleep(2000);
		bool firstPlayer = true;
		do
		{
			system("cls");
			printBoard();
			string move;
			cout << recent << "'s turn\n";
			do
			{
				cout << "Enter your move: ";
				getline(cin, move);
			} while (checkValidInput(move) == false);
			MakeAMove(move, firstPlayer);
			firstPlayer = !firstPlayer;
			recent = (recent == fname ? sname : fname);
		} while (checkWin(isBlockTwoSides, playerWin) == -1);
		system("cls");
		printBoard();
		if (playerWin == ' ')
		{
			cout << "Game ends with a draw!";
		}
		else
		{
			cout << (playerWin == 'X' ? recent : (recent == fname ? sname : fname)) << " wins!";
		}
	}
};

int main()
{
	srand((unsigned int)time(NULL));
	TicTacToe t;
	t.startGame();
}