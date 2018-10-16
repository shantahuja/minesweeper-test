//minesweeper
#ifndef MINE_SWEEPER_H
#define MINE_SWEEPER_H

#include <iostream>
#include <cstdlib>
#include<time.h>
#include <string>
#include "Board.h"

using namespace std;

class Mine_Sweeper
{
public:
	void Play();
};

void Mine_Sweeper::Play()
{
	bool again = true;
	bool over = false;
	char grid_size;
	char response;
	Board game;
	while (again == true)
	{
		cout << "Welcome to Mine Sweeper\n\n";

		cout << "What grid do you want to play with (Admin, Beginner, Intermediate, Expert)?" << endl;
		cout << "please answer with a, b, i, or e";
		cin >> grid_size;

		grid_size = toupper(grid_size);

		switch (grid_size)
		{
		case 'A':
		{
			Array2D<Cell> covered_board(3, 3);
			Array2D<Cell> uncovered_board(3, 3);

			int mines = 1;
			int count = 0;
			Cell current_symbol;
			int decision;
			std::size_t row = 0;
			std::size_t col = 0;
			std::size_t total_row = covered_board.getRow();
			std::size_t total_col = covered_board.getColumn();
			std::size_t total = ((total_row * total_col) - mines);

			srand(time(NULL));

			game.initialize_Board(covered_board, uncovered_board);
			game.setMines(uncovered_board, mines);
			game.calculateNumbers(uncovered_board);

			do
			{
				row = 10;
				col = 10;
				game.printBoard(covered_board);
				cout << "please choose an option" << endl;
				cout << "1. open a cell" << endl;
				cout << "2. mark a cell" << endl;
				cout << "3. quit" << endl;
				cin >> decision;
				switch (decision)
				{
				case 1:
				{
					cout << "Enter Row and Column";
					cin >> row
						>> col;
					if (row < 0 || row >= total_row || col < 0 || col >= total_col)
					{
						cout << "\nRow and column entered are illegal!\n";
						cout << "Please Enter a row between 1 and " << total_row << ", and a column between 1 and " << total_col;
						cout << endl;
						system("pause");
						system("CLS");
						break;
					}
					if (covered_board[row][col].getCell() == symbol::covered);
					{
						covered_board[row][col].setSymbol(uncovered_board[row][col].getSymbol());

						if (covered_board[row][col].getSymbol() == ' ')
						{
							game.openCell(uncovered_board, covered_board, row, col, count);
						}

						if (covered_board[row][col].getSymbol() != '*')
						{
							count++;
						}
					}
					break;
				}
				case 2:
				{
					cout << "What position do you want to mark?";
					cin >> row
						>> col;
					game.setMark(covered_board, uncovered_board, row, col);
					break;
				}
				case 3:
				{
					break;
				}
				}
			} while (decision != 3 && count < total && covered_board[row][col].getSymbol() != '*' && game.getMark() != mines);

			if (count == total || game.getMark() == mines)
			{
				game.printBoard(uncovered_board);
				cout << "\nYOU WIN\n";
			}
			else
			{
				for (int i = 0; i < total_row; i++)
				{
					for (int j = 0; j < total_col; j++)
					{
						if (uncovered_board[i][j].getCell() == symbol::bomb)
						{
							covered_board[i][j].setSymbol('*');
						}
					}
				}
				game.printBoard(uncovered_board);
				cout << "\nYOU LOSE\n";
			}
			break;
		}
		case 'B':
		{
			Array2D<Cell> covered_board(10, 10);
			Array2D<Cell> uncovered_board(10, 10);

			int mines = 10;
			int count = 0;
			Cell current_symbol;
			int decision;
			std::size_t row = 0;
			std::size_t col = 0;
			std::size_t total_row = covered_board.getRow();
			std::size_t total_col = covered_board.getColumn();
			std::size_t total = ((total_row * total_col) - mines);

			srand(time(NULL));

			game.initialize_Board(covered_board, uncovered_board);
			game.setMines(uncovered_board, mines);
			game.calculateNumbers(uncovered_board);

			do
			{
				row = 10;
				col = 10;
				game.printBoard(covered_board);
				cout << "please choose an option" << endl;
				cout << "1. open a cell" << endl;
				cout << "2. mark a cell" << endl;
				cout << "3. quit" << endl;
				cin >> decision;
				switch (decision)
				{
				case 1:
				{
					cout << "Enter Row and Column";
					cin >> row
						>> col;
					if (row < 0 || row >= total_row || col < 0 || col >= total_col)
					{
						cout << "\nRow and column entered are illegal!\n";
						cout << "Please Enter a row between 1 and " << total_row << ", and a column between 1 and " << total_col;
						cout << endl;
						system("pause");
						system("CLS");
						continue;
					}
					if (covered_board[row][col].getCell() == symbol::covered);
					{
						covered_board[row][col].setSymbol(uncovered_board[row][col].getSymbol());

						if (covered_board[row][col].getSymbol() == ' ')
						{
							game.openCell(uncovered_board, covered_board, row, col, count);
						}

						if (covered_board[row][col].getSymbol() != '*')
						{
							count++;
						}
					}
					break;
				}
				case 2:
				{
					cout << "What position do you want to mark?";
					cin >> row
						>> col;
					game.setMark(covered_board, uncovered_board, row, col);
					break;
				}
				case 3:
				{
					break;
				}
				}
			} while (decision != 3 && count < total && covered_board[row][col].getSymbol() != '*' && game.getMark() != mines);

			if (count == total || game.getMark() == mines)
			{
				game.printBoard(uncovered_board);
				cout << "\nYOU WIN\n";
			}
			else
			{
				for (int i = 0; i < total_row; i++)
				{
					for (int j = 0; j < total_col; j++)
					{
						if (uncovered_board[i][j].getCell() == symbol::bomb)
						{
							covered_board[i][j].setSymbol('*');
						}
					}
				}
				game.printBoard(uncovered_board);
				cout << "\nYOU LOSE\n";
			}
			break;
		}
		case 'I':
		{
			Array2D<Cell> covered_board(16, 16);
			Array2D<Cell> uncovered_board(16, 16);

			int mines = 40;
			int count = 0;
			Cell current_symbol;
			int decision;
			std::size_t row = 0;
			std::size_t col = 0;
			std::size_t total_row = covered_board.getRow();
			std::size_t total_col = covered_board.getColumn();
			std::size_t total = ((total_row * total_col) - mines);

			srand(time(NULL));

			game.initialize_Board(covered_board, uncovered_board);
			game.setMines(uncovered_board, mines);
			game.calculateNumbers(uncovered_board);

			do
			{
				row = 10;
				col = 10;
				game.printBoard(covered_board);
				cout << "please choose an option" << endl;
				cout << "1. open a cell" << endl;
				cout << "2. mark a cell" << endl;
				cout << "3. quit" << endl;
				cin >> decision;
				switch (decision)
				{
				case 1:
				{
					cout << "Enter Row and Column";
					cin >> row
						>> col;
					if (row < 0 || row >= total_row || col < 0 || col >= total_col)
					{
						cout << "\nRow and column entered are illegal!\n";
						cout << "Please Enter a row between 1 and " << total_row << ", and a column between 1 and " << total_col;
						cout << endl;
						system("pause");
						system("CLS");
						continue;
					}
					if (covered_board[row][col].getCell() == symbol::covered);
					{
						covered_board[row][col].setSymbol(uncovered_board[row][col].getSymbol());

						if (covered_board[row][col].getSymbol() == ' ')
						{
							game.openCell(uncovered_board, covered_board, row, col, count);
						}

						if (covered_board[row][col].getSymbol() != '*')
						{
							count++;
						}
					}
					break;
				}
				case 2:
				{
					cout << "What position do you want to mark?";
					cin >> row
						>> col;
					game.setMark(covered_board, uncovered_board, row, col);
					break;
				}
				case 3:
				{
					break;
				}
				}
			} while (decision != 3 && count < total && covered_board[row][col].getSymbol() != '*' && game.getMark() != mines);

			if (count == total || game.getMark() == mines)
			{
				game.printBoard(uncovered_board);
				cout << "\nYOU WIN\n";
			}
			else
			{
				for (int i = 0; i < total_row; i++)
				{
					for (int j = 0; j < total_col; j++)
					{
						if (uncovered_board[i][j].getCell() == symbol::bomb)
						{
							covered_board[i][j].setSymbol('*');
						}
					}
				}
				game.printBoard(uncovered_board);
				cout << "\nYOU LOSE\n";
			}
			break;
		}
		case 'E':
		{
			Array2D<Cell> covered_board(16, 30);
			Array2D<Cell> uncovered_board(16, 30);

			int mines = 100;
			int count = 0;
			Cell current_symbol;
			int decision;
			std::size_t row = 0;
			std::size_t col = 0;
			std::size_t total_row = covered_board.getRow();
			std::size_t total_col = covered_board.getColumn();
			std::size_t total = ((total_row * total_col) - mines);

			srand(time(NULL));

			game.initialize_Board(covered_board, uncovered_board);
			game.setMines(uncovered_board, mines);
			game.calculateNumbers(uncovered_board);

			do
			{
				row = 10;
				col = 10;
				game.printBoard(covered_board);
				cout << "please choose an option" << endl;
				cout << "1. open a cell" << endl;
				cout << "2. mark a cell" << endl;
				cout << "3. quit" << endl;
				cin >> decision;
				switch (decision)
				{
				case 1:
				{
					cout << "Enter Row and Column";
					cin >> row
						>> col;
					if (row < 0 || row >= total_row || col < 0 || col >= total_col)
					{
						cout << "\nRow and column entered are illegal!\n";
						cout << "Please Enter a row between 1 and " << total_row << ", and a column between 1 and " << total_col;
						cout << endl;
						system("pause");
						system("CLS");
						continue;
					}
					if (covered_board[row][col].getCell() == symbol::covered);
					{
						covered_board[row][col].setSymbol(uncovered_board[row][col].getSymbol());

						if (covered_board[row][col].getSymbol() == ' ')
						{
							game.openCell(uncovered_board, covered_board, row, col, count);
						}

						if (covered_board[row][col].getSymbol() != '*')
						{
							count++;
						}
					}
					break;
				}
				case 2:
				{
					cout << "What position do you want to mark?";
					cin >> row
						>> col;
					game.setMark(covered_board, uncovered_board, row, col);
					break;
				}
				case 3:
				{
					break;
				}
				}
			} while (decision != 3 && count < total && covered_board[row][col].getSymbol() != '*' && game.getMark() != mines);

			if (count == total || game.getMark() == mines)
			{
				game.printBoard(uncovered_board);
				cout << "\nYOU WIN\n";
			}
			else
			{
				for (int i = 0; i < total_row; i++)
				{
					for (int j = 0; j < total_col; j++)
					{
						if (uncovered_board[i][j].getCell() == symbol::bomb)
						{
							covered_board[i][j].setSymbol('*');
						}
					}
				}
				game.printBoard(uncovered_board);
				cout << "\nYOU LOSE\n";
			}
			break;
		}
		}

		cout << "Would you like to play again?";
		cin >> response;
		if (response == 'y' || response == 'Y')
		{
			again = true;
		}
		else
			again = false;
	}
	system("CLS");
	cout << "Goodbye\n";
}
#endif