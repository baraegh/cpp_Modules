

#ifndef CONVERTOR_HPP
# define CONVERTOR_HPP

# include <string>
# include <iostream>
# include <sstream>
# include <climits>
# include <iomanip>
# include <cmath>

class Convertor
{
    private:
        std::string _str;
        char        _char_value;
        int         _int_value;
        double      _double_value;
        float       _float_value;
        int         _type;
        int         _status[4];
        enum        Type
        {
            charType,
            intType,
            floatType,
            doubleType,
            invalidType
        };
        void        fromChar();
        void        fromInt();
        void        fromFloat();
        void        fromDouble();
        void        parsing();

    public:
        Convertor();
        Convertor(std::string str);
        Convertor(Convertor const & obj);
        ~Convertor();

        Convertor & operator=(Convertor const & obj);
        char        getCharValue() const;
        int         getIntValue() const;
        float       getFloatValue() const;
        double      getDoubleValue() const;
        void        printValues();
        
};

#endif