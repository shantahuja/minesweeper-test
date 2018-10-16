#ifndef ROW_H
#define ROW_H
#include "Array2D.h"

template <class T>
class Array2D;

template <class T>
class Row
{
private:
	const Array2D<T> & m_array2D;
	int m_row;
public:
	Row(const Array2D<T> & in_array, int row);
	T & operator [](int column);
};

template<class T>
inline Row<T>::Row(const Array2D<T> & in_array, int row) : m_array2D(in_array), m_row(row) {}

template<class T>
inline T & Row<T>::operator[](int column)
{
	return m_array2D.Select(m_row, column);
}

#endif // !ROW_H
