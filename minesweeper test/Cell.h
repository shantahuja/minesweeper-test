//Cell
#ifndef CELL_H
#define CELL_H
#include <iostream>
using namespace std;

enum symbol { bomb = 0, marked = 1, covered = 2, uncovered = 3 };

class Cell
{
	symbol m_content;
	std::size_t m_number = 0;
public:
	Cell();
	Cell(symbol content, std::size_t number);
	//make copy constructor
	void setContent(symbol content);
	void setNumber(std::size_t number);
	int getCell();
	int getNumber();
	char getSymbol();
	void setSymbol(char symbol);
};

inline Cell::Cell() : m_content(symbol::uncovered) {}

inline Cell::Cell(symbol content, std::size_t number)
{
	m_content = content;
	m_number = number;
}

inline void Cell::setContent(symbol content)
{
	m_content = content;
}

inline void Cell::setNumber(std::size_t number)
{
	m_number = number;
}

inline int Cell::getCell()
{
	return m_content;
}

inline int Cell::getNumber()
{
	return m_number;
}
inline char Cell::getSymbol()
{
	if (getCell() == symbol::bomb)
	{
		return '*';
	}
	else if (getCell() == symbol::uncovered)
	{
		return ' ';
	}
	else if (getCell() == symbol::covered)
	{
		return '?';
	}
	else if (getCell() == symbol::marked)
	{
		return 'M';
	}
}
inline void Cell::setSymbol(char symbol)
{
	if (symbol == '*')
	{
		m_content = symbol::bomb;
	}
	else if (symbol == ' ')
	{
		m_content = symbol::uncovered;
	}
	else if (symbol == '?')
	{
		m_content = symbol::covered;
	}
	else if (symbol == 'M')
	{
		m_content = symbol::marked;
	}
}
#endif