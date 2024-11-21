#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <stdexcept>

template<typename T>
class Array
{
	private:
		T *_arr;
		unsigned int	_size;
	public:
		Array();
		Array( unsigned int n );
		Array( Array const &arr );
		Array &operator=( Array const &arr );
		T &operator[]( unsigned int i );
		~Array();

		unsigned int size( void ){ return _size; };
};

template<typename T>
Array<T>::Array()
{
	_arr = new T();
	_size = 0;
}

template<typename T>
Array<T>::Array( unsigned int n )
{
	_arr = new T[n];
	for (unsigned int  i = 0; i < n; i++)
		_arr[i] = i;
	_size = n;
}

template<typename T>
Array<T>::Array( Array const &arr )
{
	_arr = new T[arr._size];
	_size = arr._size;
	for (unsigned int i = 0; i < _size; i++)
	{
		_arr[i] = arr._arr[i];
	}
}

template<typename T>
Array<T> &Array<T>::operator=( Array const &arr )
{
	if (this != &arr)
	{
		delete [] _arr;
		_arr = new T[arr._size];
		_size = arr._size;
		for (unsigned int i = 0; i < _size; i++)
		{
			_arr[i] = arr._arr[i];
		}
	}
	return *this;
}

template<typename T>
T &Array<T>::operator[]( unsigned int i )
{
	if (i >= _size)
	{
		throw std::out_of_range ("error: index out of range");
	}
	return _arr[i];
}

template<typename T>
Array<T>::~Array()
{
	delete [] _arr;
}

#endif