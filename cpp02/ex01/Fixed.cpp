

#include "Fixed.hpp"

Fixed::Fixed(void) :nbr(0)
{
    std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(Fixed const & src)
{
    std::cout << "Copy constructor called" << std::endl;
    *this = src;
}

Fixed::~Fixed(void)
{
    std::cout << "Destructor called" << std::endl;
}

Fixed::Fixed(int const nbr) :nbr(nbr << n)
{
    std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(float const f_nbr) : nbr(roundf(f_nbr * (1 << n)))
{
    std::cout << "Float constructor called" << std::endl;
}

std::ostream    & operator<<(std::ostream &o, Fixed const & rhs)
{
    o << rhs.toFloat();
    return o;
}

Fixed   &Fixed::operator=(Fixed const & rhs)
{
    std::cout << "Copy assignment operator called" << std::endl;
    this->nbr = rhs.getRawBits();
    return *this;
}

int Fixed::getRawBits( void ) const
{
    return this->nbr;
}

void Fixed::setRawBits(int const raw)
{
    this->nbr = raw;
}

float   Fixed::toFloat( void ) const
{
    return  (float) this->nbr / (1 << n);
}

int     Fixed::toInt( void ) const
{
    return this->nbr >> n;
}