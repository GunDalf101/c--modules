# include "Span.hpp"

Span::Span(unsigned int n) : _n(n)
{
    _v.reserve(n);
}

Span::Span(const Span &other)
{
    *this = other;
}

Span &Span::operator=(const Span &other)
{
    _n = other._n;
    _v = other._v;
    return *this;
}

Span::~Span()
{
}

void Span::addNumber(int n)
{
    if (_v.size() == _n)
        throw std::exception();
    _v.push_back(n);
}

int Span::shortestSpan()
{
    if (_v.size() < 2)
        throw NoSpanException();
    std::vector<int> v = _v;
    std::sort(v.begin(), v.end());
    int min = v[1] - v[0];
    for (unsigned int i = 2; i < v.size(); i++)
    {
        int diff = v[i] - v[i - 1];
        if (diff < min)
            min = diff;
    }
    return min;
}

int Span::longestSpan()
{
    if (_v.size() < 2)
        throw NoSpanException();
    std::vector<int> v = _v;
    std::sort(v.begin(), v.end());
    return v[v.size() - 1] - v[0];
}

const char *Span::NoSpanException::what() const throw()
{
    return "No span to find";
}
