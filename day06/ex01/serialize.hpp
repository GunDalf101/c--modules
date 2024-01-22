#ifndef SERIALIZE_HPP
# define SERIALIZE_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <exception>
# include <stdlib.h>

class Data {
    public:
        virtual ~Data() {}
};

class Serializer {
    private:
        std::string const	_str;
        Serializer();
    public:
        Serializer(std::string const &str);
        Serializer(Serializer const &copy);
        virtual ~Serializer();

        Serializer &operator=(Serializer const &copy);

        std::string const	&getStr() const;
        static uintptr_t            serialize(Data *ptr);
        static Data                 *deserialize(uintptr_t raw);
};

#endif