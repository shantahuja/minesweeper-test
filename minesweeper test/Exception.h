#ifndef EXCEPTION_H
#define EXCEPTION_H
#include <fstream>
#include <string>


class Exception
{
private:
	char m_msg[256];
public:
	Exception();
	Exception(char * msg);
	Exception(const Exception & copy);
	~Exception();
	Exception & operator =(const Exception & rhs);
	const char * getMessage();
	void setMessage(char * msg);
	const wchar_t * getMessageWcharT() const;
	const wchar_t * getMessageWcharT();
	friend std::ostream & operator <<(std::ostream & stream, const Exception & except) //insertion operator
	{
		stream << except.m_msg;
		return stream;
	}
};

inline Exception::Exception()
{
	//set equal to null string using strcpy first paramater m_msg, second ""
}

inline Exception::Exception(char * msg) //may need to put const
{
	strcpy(m_msg, msg);
}

inline Exception::Exception(const Exception & copy)
{
		strcpy(m_msg, copy.m_msg);
}

inline Exception::~Exception()
{
	//no need to delete anything due to not newing anything up
}

inline Exception & Exception::operator=(const Exception & rhs)
{
	strcpy(m_msg, rhs.m_msg); //use the accessor
}

inline const char * Exception::getMessage()
{
	return m_msg;
}

inline void Exception::setMessage(char * msg)
{
	strcpy(m_msg, msg);
}

inline const wchar_t * Exception::getMessageWcharT() const
{
	const size_t size = strlen(m_msg) + 1;
	wchar_t* wText = new wchar_t[size];
	mbstowcs(wText, m_msg, size);
	return wText;
}

inline const wchar_t * Exception::getMessageWcharT()
{
	const size_t size = strlen(m_msg) + 1;
	wchar_t* wText = new wchar_t[size];
	mbstowcs(wText, m_msg, size);
	return wText;
}

#endif // !EXCEPTION_H
