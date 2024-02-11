#ifndef SPAN_HPP
#define SPAN_HPP

#include <iostream>
#include <vector>
#include <algorithm>
#include <exception>

class Span
{
    private:
        unsigned int _n;
        std::vector<int> _v;
    public:
        Span(unsigned int n);
        Span(const Span &other);
        Span &operator=(const Span &other);
        ~Span();
        void addNumber(int n);
        int shortestSpan();
        int longestSpan();
        class NoSpanException : public std::exception
        {
            public:
                virtual const char *what() const throw();
        };
};

#endif