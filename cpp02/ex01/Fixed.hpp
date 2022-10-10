
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
};

std::ostream    & operator<<(std::ostream &o, Fixed const & rhs);

#endif