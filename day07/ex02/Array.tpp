template <typename T>
Array<T>::Array() : _array(NULL), _size(0) {}

template <typename T>
Array<T>::Array(unsigned int n) : _array(new T[n]), _size(n) {}

template <typename T>
Array<T>::Array(Array const &copy) : _array(NULL), _size(0)
{
    *this = copy;
}

template <typename T>
Array<T>::~Array()
{
    if (this->_array)
        delete [] this->_array;
}

template <typename T>
Array<T> &Array<T>::operator=(Array const &copy)
{
    if (this != &copy)
    {
        if (this->_array)
            delete [] this->_array;
        this->_array = new T[copy._size];
        for (unsigned int i = 0; i < copy._size; i++)
            this->_array[i] = copy._array[i];
        this->_size = copy._size;
    }
    return (*this);
}

template <typename T>
T &Array<T>::operator[](unsigned int i)
{
    if (i >= this->_size)
        throw OutOfRangeException();
    return (this->_array[i]);
}

template <typename T>
unsigned int Array<T>::size() const
{
    return (this->_size);
}

template <typename T>
const char *Array<T>::OutOfRangeException::what() const throw()
{
    return ("Out of range");
}