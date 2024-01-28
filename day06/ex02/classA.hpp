#ifndef CLASSA_HPP
# define CLASSA_HPP

# include "Base.hpp"

class ClassA : public Base
{
    public:
        ClassA();
        ClassA(ClassA const &copy);
        virtual ~ClassA();
        ClassA &operator=(ClassA const &copy);
};

#endif