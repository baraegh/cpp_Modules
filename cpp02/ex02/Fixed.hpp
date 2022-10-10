
#ifndef FIXED_HPP
#define FIXED_HPP

# include <iostream>
# include <cmath>

class Fixed
{
    private :
        int             nbr;
        static const int n = 8;

    public :
        Fixed(void);
        ~Fixed(void);
        Fixed(Fixed const & src);
        Fixed(int const nbr);
        Fixed(float const f_nbr);

        int     getRawBits(void) const;
        void    setRawBits(int const raw);
        float   toFloat( void ) const;
        int     toInt( void ) const;

        Fixed   & operator=(Fixed const & rhs);

        /* Arithmetic operators */
        Fixed   operator+(Fixed const & rhs);
        Fixed   operator-(Fixed const & rhs);
        Fixed   operator*(Fixed const & rhs);
        Fixed   operator/(Fixed const & rhs);

        /* increment/decrement operators */
        Fixed   & operator++(void);
        Fixed     operator++(int);
        Fixed   & operator--(void);
        Fixed     operator--(int);

        /*  overloaded member functions */
        static Fixed & min(Fixed & a, Fixed & b);
        static const Fixed & min(Fixed const & a, Fixed const & b);
        static Fixed & max(Fixed & a, Fixed & b);
        static const Fixed & max(Fixed const & a, Fixed const & b);
};

/* Comparison operators */
bool   operator>(Fixed const & a, Fixed const & b);
bool   operator<(Fixed const & a, Fixed const & b);
bool   operator==(Fixed const & a, Fixed const & b);
bool   operator!=(Fixed const & a, Fixed const & b);
bool   operator>=(Fixed const & a, Fixed const & b);
bool   operator<=(Fixed const & a, Fixed const & b);

/* I/O operators */
std::ostream    & operator<<(std::ostream &o, Fixed const & obj);

#endif