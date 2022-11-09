
#include "Convertor.hpp"

Convertor::Convertor()
    :_str("")
{
    Convertor(this->_str);
}

Convertor::Convertor(std::string str)
    :_str(str)
{
    for (int i = 0; i < 4; i++)
        this->_status[i] = 0;
    this->parsing();
    switch (this->_type)
    {
        case charType:
            fromChar();
            break;
        case intType:
            fromInt();
            break;
        case floatType:
            fromFloat();
            break;
        case doubleType:
            fromDouble();
            break;
        case invalidType:
        {
            for (int i = 0; i < 4; i++)
                this->_status[i] = 1;
            break;
        }
        default:
            break;
    }
}

Convertor::Convertor(Convertor const & obj)
{
    *this = obj;
}

Convertor & Convertor::operator=(Convertor const & obj)
{
    this->_str = obj._str;
    this->_char_value = obj._char_value;
    this->_int_value = obj._int_value;
    this->_float_value = obj._float_value;
    this->_double_value = obj._double_value;
    for (int i = 0; i < 4; i++)
        this->_status[i] = obj._status[i];
    return *this;
}

Convertor::~Convertor(){}

void    Convertor::parsing()
{
    long unsigned int     i = 0;

    if (_str == "-inff" || _str == "+inff" || _str == "nanf"
        || _str == "inff")
    {
        this->_type = floatType;
        this->_float_value =  atof(_str.c_str());
        return;
    }
    if (_str == "-inf" || _str == "+inf" || _str == "nan"
        || _str == "inf")
    {
        this->_type = doubleType;
        this->_double_value = atof(_str.c_str());
        return;
    }
    if (_str[i] == '-' || _str[i] == '+' || isdigit(_str[i]))
    {
        if ((_str[i] == '-' || _str[i] == '+') && _str.length() == 1)
        {
            this->_type = charType;
            this->_char_value = _str[0];
            return;
        }
        i++;
        if (_str[i] == '-' || _str[i] == '+')
        {
            this->_type = invalidType;
            return;
        }
        else if (isalpha(_str[i]) || ((_str[i] == '-' || _str[i] == '+') && _str[i] == '.'))
        {
            this->_type = invalidType;
            return;
        }
        for (; i < _str.length(); i++)
        {
            if (_str[i] == '.' )
            {
                if (_str[_str.length() - 1] == 'f')
                {
                    this->_type = floatType;
                    this->_float_value = atof(_str.c_str());
                    return;
                }
                i++;
                for( ; i < _str.length(); i++)
                {
                    if (isalpha(_str[i]))
                    {
                        this->_type = invalidType;
                        return;
                    }
                    this->_type = doubleType;
                    this->_double_value = atof(_str.c_str());
                    return;
                }
            }
            else if (isalpha(_str[i]))
            {
                this->_type = invalidType;
                return;
            }
        }
        this->_type = intType;
        long int lnbr = atol(_str.c_str());
        if (lnbr > INT_MAX || lnbr < INT_MIN)
        {
            this->_type = invalidType;
            return;
        }
        this->_int_value = atoi(_str.c_str());
        return;
    }
    if (isalpha(_str[i]))
    {
        if (_str.length() > 1)
        {
            this->_type = invalidType;
            return;
        }
        this->_type = charType;
        this->_char_value = _str[0];
        return;
    }
}

void    Convertor::fromChar()
{
    this->_char_value = this->_str[0];
    if (!isprint(this->_char_value))
        this->_status[0] = 2;
    this->_int_value = static_cast<int>(this->_char_value);
    this->_float_value = static_cast<float>(this->_char_value);
    this->_double_value = static_cast<double>(this->_char_value);
}

void    Convertor::fromInt()
{
    if (this->_int_value > 127 || this->_int_value < 0)
        this->_status[0] = 1;
    else if (!isprint(this->_int_value))
        this->_status[0] = 2;
    this->_char_value = static_cast<char>(this->_int_value);
    this->_float_value = static_cast<float>(this->_int_value);
    this->_double_value = static_cast<double>(this->_int_value);
}

void    Convertor::fromFloat()
{
    if (this->_float_value > INT_MAX || this->_float_value < INT_MIN)
        this->_status[1] = 1;
    this->_char_value = static_cast<char>(this->_float_value);
    this->_int_value = static_cast<int>(this->_float_value);
    if (this->_int_value > INT_MAX || this->_int_value < INT_MIN
        || std::isnan(this->_float_value) || std::isnan(this->_float_value))
    {
        this->_status[1] = 1;
        this->_status[0] = 1;
    }
    else if (this->_int_value > 127 || this->_int_value < 0)
        this->_status[0] = 1;
    else if (!isprint(this->_int_value))
        this->_status[0] = 2;
    this->_double_value = static_cast<double>(this->_double_value);
}

void    Convertor::fromDouble()
{
    if (this->_double_value > INT_MAX || this->_double_value < INT_MIN
        || std::isnan(this->_double_value) || std::isnan(this->_double_value))
    {
        this->_status[1] = 1;
        this->_status[0] = 1;
    }
    this->_char_value = static_cast<char>(this->_double_value);
    this->_int_value = static_cast<int>(this->_double_value);
    if (this->_int_value > 127 || this->_int_value < 0)
        this->_status[0] = 1;
    else if (!isprint(this->_int_value))
        this->_status[0] = 2;
    this->_float_value = static_cast<float>(this->_double_value);
}

char    Convertor::getCharValue() const
{
    return this->_char_value;
}

int Convertor::getIntValue() const
{
    return this->_int_value;
}

float   Convertor::getFloatValue() const
{
    return this->_float_value;
}

double  Convertor::getDoubleValue() const
{
    return this->_double_value;
}

void    Convertor::printValues()
{
    std::stringstream   strStream;
    std::string         str;

    std::cout << "char: ";
    if (this->_status[0] == 1)
        std::cout << "impossible\n";
    else if (this->_status[0] == 2)
        std::cout << "Non displayable\n";
    else
        std::cout << "'" << this->getCharValue() << "'" << std::endl;
    
    std::cout << "int: ";
    if (this->_status[1] == 1)
        std::cout << "impossible\n";
    else if (this->_status[1] == 2)
        std::cout << "Non displayable\n";
    else
        std::cout << this->getIntValue() << std::endl;
    
    std::cout << "float: ";
    if (this->_status[2] == 1)
        std::cout << "impossible\n";
    else if (this->_status[2] == 2)
        std::cout << "Non displayable\n";
    else
    {
        strStream << this->getFloatValue();
        str = strStream.str();
        if (!(std::isnan(this->getFloatValue())
            || std::isinf(this->getFloatValue()))
            && str.find('.') == std::string::npos)
            strStream << ".0";
        std::cout << strStream.str() << "f\n";
    }
    
    std::cout << "double: ";
    if (this->_status[3] == 1)
        std::cout << "impossible\n";
    else if (this->_status[3] == 2)
        std::cout << "Non displayable\n";
    else
        std::cout << strStream.str() << std::endl;
}