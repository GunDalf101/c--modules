#ifndef CLASSB_HPP
# define CLASSB_HPP

# include "Base.hpp"

class ClassB : public Base
{
    public:
        ClassB();
        ClassB(ClassB const &copy);
        virtual ~ClassB();
        ClassB &operator=(ClassB const &copy);
};

#endif