#ifndef ARRAY_HPP
# define ARRAY_HPP

#include <exception>

template <typename T>
class Array
{
public:
	class OutOfRangeException : public std::exception
	{
	public:
		virtual const char* what(void) const throw()
		{
			return "Array: index out of range";
		}
	};

private:
	T* data;
	unsigned int len;

public:
	Array(void) : data(new T[0]()), len(0)
	{}

	Array(unsigned int n) : data(new T[n]()), len(n)
	{}

	Array(const Array& other) : data(new T[other.len]), len(other.len)
	{
		for (unsigned int i = 0; i < len; i++)
			data[i] = other.data[i];
	}

	Array& operator=(const Array& other)
	{
		if (this != &other)
		{
			delete[] data;
			data = new T[other.len];
			len = other.len;
			for (unsigned int i = 0; i < len; i++)
				data[i] = other.data[i];
		}
		return *this;
	}

	~Array(void)
	{
		delete[] data;
	}

	T& operator[](unsigned int i)
	{
		if (i >= len)
			throw OutOfRangeException();
		return data[i];
	}

	const T& operator[](unsigned int i) const
	{
		if (i >= len)
			throw OutOfRangeException();
		return data[i];
	}

	unsigned int size(void) const
	{
		return len;
	}
};

#endif