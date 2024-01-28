#ifndef ARRAY_HPP
# define ARRAY_HPP

# include <iostream>
# include <string>

template <typename T>
class Array
{
    private:
        T *_array;
        unsigned int _size;

    public:
        Array();
        Array(unsigned int n);
        Array(Array const &copy);
        virtual ~Array();
        Array &operator=(Array const &copy);
        T &operator[](unsigned int i);
        unsigned int size() const;

        class OutOfRangeException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};

# include "Array.tpp"

#endif