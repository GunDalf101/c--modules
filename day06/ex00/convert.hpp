#ifndef CONVERT_HPP
# define CONVERT_HPP

# include <iostream>
# include <string>
# include <iomanip>
# include <exception>
# include <stdlib.h>

class Convert {
    private:
        std::string const	_str;
        Convert();
    public:
        Convert(std::string const &str);
        Convert(Convert const &copy);
        virtual ~Convert();

        Convert &operator=(Convert const &copy);

        std::string const	&getStr() const;
        static void			convert(std::string &str);
};

#endif