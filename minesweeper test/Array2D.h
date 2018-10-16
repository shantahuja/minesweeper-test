#ifndef ARRAY2D_H
#define ARRAY2D_H
#include "Array.h"
#include "Row.h"
#include "Exception.h"

template <class T>
class Row;

template <class T>
class Array2D
{
private:
	Array<T> m_array;
	int m_row;
	int m_col;
public:
	Array2D();
	Array2D(int row, int col);
	Array2D(const Array2D & copy);
	~Array2D();
	Array2D & operator =(const Array2D & rhs);
	Row<T> operator [](int index);
	Row<T> operator [](int index) const;
	int getRow();
	int getRow() const;
	void setRow(int rows);
	int getColumn();
	int getColumn() const;
	void setColumn(int columns);
	T & Select(int row, int column);
	T & Select(int row, int column) const;
};

template <class T>
//make sure that default constructor has row, column, and length of zero
inline Array2D<T>::Array2D() : m_row(0), m_col(0)
{
	m_array.setLength(0);
}

template<class T>
//make sure row, col, and length equal to what you set it
inline Array2D<T>::Array2D(int row, int col)
{
	try
	{
		if (row < 0)
		{
			throw Exception();
		}
		if (col < 0)
		{
			throw Exception();
		}
		m_array.setLength((row)*(col));
		m_row = row;
		m_col = col;
	}
	catch (std::bad_alloc ba)
	{
		throw ba;
	}
}

template<class T>
//copy constructor equal test
inline Array2D<T>::Array2D(const Array2D & copy)
{
	m_array.setLength((copy.getRow()) * (copy.getColumn()));
	m_row = copy.getRow();
	m_col = copy.getColumn();
	m_array = copy.m_array;
}

template<class T>
//no test?
inline Array2D<T>::~Array2D()
{
}

template<class T>
//use assignment operator to make two 2d arrays equal each other
inline Array2D<T> & Array2D<T>::operator=(const Array2D & rhs)
{
	m_array.setLength((rhs.getRow()) * (rhs.getColumn()));
	m_row = rhs.getRow();
	m_col = rhs.getColumn();
	m_array = rhs.m_array;
	return *this;
}

template<class T>
inline Row<T> Array2D<T>::operator[](int index)
{
	return Row<T>(*this, index);
}

template<class T>
inline Row<T> Array2D<T>::operator[](int index) const
{
	return Row<T>(*this, index);
}

template<class T>
inline int Array2D<T>::getRow()
{
	return m_row;
}

template<class T>
inline int Array2D<T>::getRow() const
{
	return m_row;
}

template<class T>
//set new amount of rows and verify data inside
inline void Array2D<T>::setRow(int rows)
{
	m_array.setLength(rows*m_col);
	m_row = rows;
}

template<class T>
inline int Array2D<T>::getColumn()
{
	return m_col;
}

template<class T>
inline int Array2D<T>::getColumn() const
{
	return m_col;
}

template<class T>
inline void Array2D<T>::setColumn(int columns)
{
	Array<T> temp(m_row*columns);
	int index = 0;
	int actual_column = (m_col < columns) ? m_col : columns;
	for (int i = 0; i < m_row; i++)
	{
		for (int j = 0; j < actual_column; j++)
		{
			T value = m_array[(i*m_col) + j];
			temp[index++] = value;
		}
	}
	m_col = columns;
	m_array = temp;
}

template<class T>
inline T & Array2D<T>::Select(int row, int column)
{
	int upper_bound = m_row * m_col;
	int lower_bound = 0;
	try
	{
		int size = row * column;
		if (size <= upper_bound && size >= lower_bound && row >= 0 && column >= 0)
		{
			return m_array[((m_col*row) + column)];
		}
		else
			throw Exception();
	}
	catch (std::bad_alloc & ba)
	{
		throw ba;
	}
}

template<class T>
inline T & Array2D<T>::Select(int row, int column) const
{
	int upper_bound = m_row * m_col;
	int lower_bound = 0;
	try
	{
		int size = row * column;
		if (size <= upper_bound && size >= lower_bound && row >= 0 && column >= 0)
		{
			return m_array[((m_col*row) + column)];
		}
		else
			throw Exception();
	}
	catch (std::bad_alloc & ba)
	{
		throw ba;
	}
}

#endif // !ARRAY2D_H
