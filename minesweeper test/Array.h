#ifndef ARRAY_H
#define ARRAY_H
#include "Exception.h"
#include <math.h>
#include <new>

template <class T>
class Array
{
private:
	T * m_array;
	int m_length;
	int  m_start_index;
public:
	Array();
	Array(std::size_t length, int start_index = 0);
	Array(const Array & In_Array);
	~Array();
	Array & operator =(const Array & rhs);
	T & operator [](int index);
	T & operator [](int index) const;
	int GetActualIndex(int index);
	int GetActualIndex(int index) const;
	int getStartIndex();
	int getStartIndex() const;
	void setStartIndex(int start_index);
	int getLength();
	int getLength() const;
	void setLength(int length);	
};

template<class T>
inline Array<T>::Array() : m_array(nullptr), m_length(0), m_start_index(0) {}

template<class T>
inline Array<T>::Array(std::size_t length, int start_index) : m_array(nullptr), m_length(0), m_start_index(0)
{
	if (length < 0)
	{
		throw Exception();
	}
	m_array = new T[length];
	m_length = length;
	m_start_index = start_index;
}

template<class T>
inline Array<T>::Array(const Array<T> & In_Array) : m_array(nullptr), m_length(0), m_start_index(0)
{
	std::size_t Length = In_Array.getLength();
	if (Length < 0)
	{
		throw Exception();
	}
	m_array = new T[Length];
	m_length = Length;
	m_start_index = In_Array.getStartIndex();
	for (int i = 0; i < Length; i++)
	{
		m_array[i] = In_Array.m_array[i];
	}
}

template<class T>
inline Array<T>::~Array()
{
	delete []m_array;
}

template<class T>
inline Array<T> & Array<T>::operator=(const Array & rhs)
{
	if (&rhs != this)
	{
		delete[]m_array;
		std::size_t Length = rhs.getLength();
		m_array = new T[Length];
		m_length = Length;
		m_start_index = rhs.getStartIndex();
		for (int i = 0; i < Length; i++)
		{
			m_array[i] = rhs.m_array[i];
		}
	}
	else
	{
		throw Exception();
	}
	return *this;
}

template<class T>
inline T & Array<T>::operator[](const int index)
{
	int upper_bound = m_start_index + m_length; //Sets the upper boundary(how high you can go)
	int lower_bound = m_start_index; //Sets the lower boundary(how low you can go)
	int actual_index = 0;

	if (index <= upper_bound && index >= lower_bound) //checks to see if we're within the boundaries to access
	{
		actual_index = GetActualIndex(index); //call the function that calculates the actual index
		return m_array[actual_index]; //return the actual index of the array
	}
}

template<class T>
inline T & Array<T>::operator[](int index) const //Same as above
{
	int upper_bound = m_start_index + m_length;
	int lower_bound = m_start_index;
	int actual_index = 0;

	if (index <= upper_bound && index >= lower_bound)
	{
		actual_index = GetActualIndex(index);
		return m_array[actual_index];
	}
}

template<class T>
inline int Array<T>::GetActualIndex(int index) //Calculates the actual index
{
	int actual_index = 0;
	if (m_start_index < 0)
	{
		actual_index = index - abs(m_start_index);
		return actual_index;
	}
	else
	{
		actual_index = index - m_start_index;
		return actual_index;
	}
}

template<class T>
inline int Array<T>::GetActualIndex(int index) const //Calculates the actual index
{
	int actual_index = 0;
	if (m_start_index < 0)
	{
		actual_index = index - abs(m_start_index);
		return actual_index;
	}
	else
	{
		actual_index = index - m_start_index;
		return actual_index;
	}
}

template<class T>
inline int Array<T>::getStartIndex()
{
	return m_start_index;
}

template<class T>
inline int Array<T>::getStartIndex() const
{
	return m_start_index;
}

template<class T>
inline void Array<T>::setStartIndex(int start_index)
{
	m_start_index = start_index;
}

template<class T>
inline int Array<T>::getLength()
{
	return m_length;
}

template<class T>
inline int Array<T>::getLength() const
{
	return m_length;
}

template<class T>
inline void Array<T>::setLength(int length)
{
	try
	{
		if (length >= 0)
		{
			T * temp = new T[length];
			int actual_length = (m_length < length) ? m_length : length;
			for (int i = 0; i < actual_length; i++)
			{
				temp[i] = m_array[i];
			}
			delete[]m_array;
			m_length = length;
			m_array = temp;
		}
		else
		{
			throw Exception();
		}


	}
	catch (std::bad_alloc ba)
	{
		throw ba;
	}
}

#endif 