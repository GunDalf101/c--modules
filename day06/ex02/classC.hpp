#ifndef CLASSC_HPP
# define CLASSC_HPP

# include "Base.hpp"

class ClassC : public Base
{
    public:
        ClassC();
        ClassC(ClassC const &copy);
        virtual ~ClassC();
        ClassC &operator=(ClassC const &copy);
};

#endif