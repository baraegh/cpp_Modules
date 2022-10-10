

#include "Fixed.hpp"

Fixed::Fixed(void) :nbr(0){}

Fixed::Fixed(Fixed const & src)
{
    *this = src;
}

Fixed::~Fixed(void){}

Fixed::Fixed(int const nbr) :nbr(nbr << n){}

Fixed::Fixed(float const f_nbr) : nbr(roundf(f_nbr * (1 << n))){}

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

Fixed   &Fixed::operator=(Fixed const & rhs)
{
    this->nbr = rhs.getRawBits();
    return *this;
}

/* Comparison operators */
bool   operator>(Fixed const & a, Fixed const &b)
{
    return a.getRawBits() > b.getRawBits();
}

bool   operator<(Fixed const & a, Fixed const &b)
{
    return a.getRawBits() < b.getRawBits();
}

bool   operator==(Fixed const & a, Fixed const &b)
{
    return a.getRawBits() == b.getRawBits();
}

bool   operator!=(Fixed const & a, Fixed const &b)
{
    return !(a == b);
}

bool   operator>=(Fixed const & a, Fixed const &b)
{
    return (a > b) || (a == b);
}

bool   operator<=(Fixed const & a, Fixed const &b)
{
    return (a < b) || (a == b);
}

/* Arithmetic operators */
Fixed   Fixed::operator+(Fixed const & rhs)
{
    Fixed   f;

    f.nbr = this->getRawBits() + rhs.getRawBits();
    return f;
}

Fixed   Fixed::operator-(Fixed const & rhs)
{
    Fixed   f;

    f.nbr = this->getRawBits() - rhs.getRawBits();
    return f;
}

Fixed   Fixed::operator*(Fixed const & rhs)
{
    return Fixed(((float)this->nbr * rhs.nbr) / (256 * 256));
}

Fixed   Fixed::operator/(Fixed const & rhs)
{
    return Fixed((float)this->nbr / rhs.nbr);
}

/* increment/decrement operators */
Fixed   & Fixed::operator++(void)
{
    ++this->nbr;
    return *this;
}

Fixed     Fixed::operator++(int)
{
    Fixed tmp(*this);


    ++(*this);
    return tmp;
}

Fixed   & Fixed::operator--(void)
{
    --this->nbr;
    return *this;
}

Fixed     Fixed::operator--(int)
{
    Fixed tmp(*this);

    --(*this);
    return tmp;
}

/*  overloaded member functions */
Fixed & Fixed::min(Fixed & a, Fixed & b)
{
    if (a < b)
        return a;
    return b;
}

const Fixed & Fixed::min(Fixed const & a, Fixed const & b)
{
    if (a < b)
        return a;
    return b;
}

Fixed & Fixed::max(Fixed & a, Fixed & b)
{
    if (a > b)
        return a;
    return b;
}

const Fixed & Fixed::max(Fixed const & a, Fixed const & b)
{
    if (a > b)
        return a;
    return b;
}

/* I/O operators */
std::ostream    & operator<<(std::ostream &o, Fixed const & rhs)
{
    o << rhs.toFloat();
    return o;
}
