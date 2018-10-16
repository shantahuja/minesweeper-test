//Board

#ifndef BOARD_H
#define BOARD_H

#include <iostream>
#include <cstdlib>
#include <time.h>
#include <iomanip>
#include <math.h>
#include "Array2D.h"
#include "Cell.h"

using namespace std;

enum position { TopLeft = 0, TopMiddle = 1, TopRight = 2, Left = 3, Right = 4, BottomLeft = 5, BottomMiddle = 6, BottomRight = 7 };

class Board
{
	Array2D<Cell> m_board;
	int _mark_count;
public:
	Board();
	Board(int row, int col);
	~Board();
	void printBoard(Array2D<Cell> covered_board);
	void initialize_Board(Array2D<Cell> &covered_board, Array2D<Cell> &uncovered_board);
	void setMines(Array2D<Cell> &uncovered_board, int mines);
	void calculateNumbers(Array2D<Cell> &uncovered_board);
	int getAdjacent(Array2D<Cell> &uncovered_board, position adjacent, int row, int col);
	bool isActualAdjacent(int index, int row, int col, Array2D<Cell> &uncovered_board);
	int countMines(Array2D<Cell> &uncovered_board, position adjacent[], int row, int col);
	void openCell(Array2D<Cell> &uncovered_board, Array2D<Cell> &covered_board, int row, int col, int& count);
	void setMark(Array2D<Cell> &covered_board, Array2D<Cell> uncovered_board, int row, int col);
	int getMark();
	int getTopLeft(Array2D<Cell> uncovered_board, int row, int col);
	int getTopMiddle(Array2D<Cell> uncovered_board, int row, int col);
	int getTopRight(Array2D<Cell> uncovered_board, int row, int col);
	int getLeft(Array2D<Cell> uncovered_board, int row, int col);
	int getRight(Array2D<Cell> uncovered_board, int row, int col);
	int getBottomLeft(Array2D<Cell> uncovered_board, int row, int col);
	int getBottomMiddle(Array2D<Cell> uncovered_board, int row, int col);
	int getBottomRight(Array2D<Cell> uncovered_board, int row, int col);
};



Board::Board() {}

Board::Board(int row, int col)
{
	m_board.setRow(row);
	m_board.setColumn(col);
}

Board::~Board() {}
inline void Board::printBoard(Array2D<Cell> board)
{
	Cell current_symbol;
	char temp;
	cout << "\n";
	cout << "   ";
	if (board.getColumn() <= 10)
	{
		for (int i = 0; i < board.getColumn(); i++)
		{
			cout << " " << i << " ";
		}
	}
	else
	{
		for (int i = 0; i < 10; i++)
		{
			cout << " " << i << " ";
		}
		for (int i = 10; i < board.getColumn(); i++)
		{
			cout << " " << i;
		}
	}
	
	cout << endl;
	for (int i = 0; i < board.getRow(); i++)
	{
		cout << setw(2) << i << " ";
		for (int j = 0; j < board.getColumn(); j++)
		{
			if (board[i][j].getNumber() > 0)
			{
				cout << " " << board[i][j].getNumber() << " ";
			}
			else
			{
				cout << " " << board[i][j].getSymbol() << " ";
			}
		}
		cout << endl;
	}
}
inline void Board::initialize_Board(Array2D<Cell> &covered_board, Array2D<Cell> &uncovered_board)
{
	for (int i = 0; i < covered_board.getRow(); i++)
	{
		for (int j = 0; j < covered_board.getColumn(); j++)
		{
			covered_board[i][j].setContent(symbol::covered);
			uncovered_board[i][j].setContent(symbol::uncovered);
		}
	}
}
inline void Board::setMines(Array2D<Cell> &uncovered_board, int mines)
{
	srand(time(NULL));

	int row_mine;
	int col_mine;
	int num_mines = 0;

	while (num_mines < mines)
	{
		row_mine = rand() % (uncovered_board.getRow());
		col_mine = rand() % (uncovered_board.getColumn());

		if (uncovered_board[row_mine][col_mine].getCell() != symbol::bomb)
		{
			uncovered_board[row_mine][col_mine].setContent(symbol::bomb);
			num_mines++;
		}
	}
}
inline void Board::calculateNumbers(Array2D<Cell> &uncovered_board)
{
	position adjacent[8]{ TopLeft, TopMiddle, TopRight, Left, Right, BottomLeft, BottomMiddle, BottomRight };
	int row = uncovered_board.getRow();
	int columns = uncovered_board.getColumn();

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < columns; j++)
		{
			if (uncovered_board[i][j].getCell() != symbol::bomb)
			{
				uncovered_board[i][j].setNumber(countMines(uncovered_board, adjacent, i, j));
			}
		}
	}
}
inline int Board::getAdjacent(Array2D<Cell> &uncovered_board, position adjacent, int row, int col)
{
	if (adjacent == position::TopLeft)
	{
		return getTopLeft(uncovered_board, row, col);
	}
	else if (adjacent == position::TopMiddle)
	{
		return getTopMiddle(uncovered_board, row, col);
	}
	else if (adjacent == position::TopRight)
	{
		return getTopRight(uncovered_board, row, col);
	}
	else if (adjacent == position::Left)
	{
		return getLeft(uncovered_board, row, col);
	}
	else if (adjacent == position::Right)
	{
		return getRight(uncovered_board, row, col);
	}
	else if (adjacent == position::BottomLeft)
	{
		return getBottomLeft(uncovered_board, row, col);
	}
	else if (adjacent == position::BottomMiddle)
	{
		return getBottomMiddle(uncovered_board, row, col);
	}
	else
		getBottomRight(uncovered_board, row, col);
}
inline bool Board::isActualAdjacent(int index, int row, int col, Array2D<Cell> &uncovered_board)
{

	if ((row - 1) < 0)
	{
		if ((col - 1) < 0)
		{
			if (index == 0 || index == 1 || index == 2 || index == 3 || index == 5)
			{
				return false;
			}
		}
		else if ((col + 1) >= uncovered_board.getColumn())
		{
			if (index == 0 || index == 1 || index == 2 || index == 4 || index == 7)
			{
				return false;
			}
		}
		else if (index == 0 || index == 1 || index == 2)
		{
			return false;
		}

	}

	if ((row + 1) >= uncovered_board.getRow())
	{
		if ((col - 1) < 0)
		{
			if (index == 0 || index == 3 || index == 5 || index == 6 || index == 7)
			{
				return false;
			}
		}
		else if ((col + 1) >= uncovered_board.getColumn())
		{
			if (index == 2 || index == 4 || index == 5 || index == 6 || index == 7)
			{
				return false;
			}
		}
		else if (index == 5 || index == 6 || index == 7)
		{
			return false;
		}
	}

	if ((col - 1) < 0)
	{
		if (index == 0 || index == 3 || index == 5)
		{
			return false;
		}
	}
	if ((col + 1) >= uncovered_board.getColumn())
	{
		if (index == 2 || index == 4 || index == 7)
		{
			return false;
		}
	}

	return true;
}
inline int Board::countMines(Array2D<Cell> &uncovered_board, position adjacent[], int row, int col) //make int
{
	int mines = 0;
	int value = 0;

	for (int i = 0; i < 8; i++)
	{
		if (isActualAdjacent(i, row, col, uncovered_board))
		{
			if (getAdjacent(uncovered_board, adjacent[i], row, col) == symbol::bomb)
			{
				mines++;
			}
		}
		if (mines == 0)
		{
			value = 0;
		}
		else
		{
			value = mines;
		}
	}
	return value;
}
inline void Board::openCell(Array2D<Cell> &uncovered_board, Array2D<Cell> &covered_board, int row, int col, int & count)
{
	covered_board[row][col] = uncovered_board[row][col];
}
inline void Board::setMark(Array2D<Cell>& covered_board, Array2D<Cell> uncovered_board, int row, int col)
{
	covered_board[row][col].setContent(symbol::marked);
	if (uncovered_board[row][col].getCell() == symbol::bomb)
	{
		_mark_count++;
	}
}
inline int Board::getMark()
{
	return _mark_count;
}
inline int Board::getTopLeft(Array2D<Cell> uncovered_board, int row, int col)
{
	if (row - 1 < 0 || col - 1 < 0)
	{
		return 0;
	}
	else
	{
		return uncovered_board[row - 1][col - 1].getCell();
	}
}
inline int Board::getTopMiddle(Array2D<Cell> uncovered_board, int row, int col)
{
	if ((row - 1) < 0)
	{
		return 0;
	}
	else
	{
		return uncovered_board[row - 1][col].getCell();
	}
}
inline int Board::getTopRight(Array2D<Cell> uncovered_board, int row, int col)
{
	if ((row - 1) < 0 || (col + 1) >= uncovered_board.getColumn())
	{
		return 0;
	}
	else
	{
		return uncovered_board[row - 1][col + 1].getCell();
	}
}
inline int Board::getLeft(Array2D<Cell> uncovered_board, int row, int col)
{
	if ((col - 1) < 0)
	{
		return 0;
	}
	else
	{
		return uncovered_board[row][col - 1].getCell();
	}
}
inline int Board::getRight(Array2D<Cell> uncovered_board, int row, int col)
{
	if ((col + 1) >= uncovered_board.getColumn())
	{
		return 0;
	}
	else
	{
		return uncovered_board[row][col + 1].getCell();
	}
}
inline int Board::getBottomLeft(Array2D<Cell> uncovered_board, int row, int col)
{
	if ((row + 1) >= uncovered_board.getRow() || (col - 1) < 0)
	{
		return 0;
	}
	else
	{
		return uncovered_board[row + 1][col - 1].getCell();
	}
}
inline int Board::getBottomMiddle(Array2D<Cell> uncovered_board, int row, int col)
{
	if ((row + 1) >= uncovered_board.getRow())
	{
		return 0;
	}
	else
	{
		return uncovered_board[row + 1][col].getCell();
	}
}
inline int Board::getBottomRight(Array2D<Cell> uncovered_board, int row, int col)
{
	if ((row + 1) >= uncovered_board.getRow() || (col + 1) >= uncovered_board.getColumn())
	{
		return 0;
	}
	else
	{
		return uncovered_board[row + 1][col + 1].getCell();
	}
}
#endif