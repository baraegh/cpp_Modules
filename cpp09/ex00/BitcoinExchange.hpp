

#ifndef BITCOINEXCHANGE_HPP
# define BITCOINEXCHANGE_HPP

# include <iostream>
# include <unistd.h>
# include <string>
# include <map>
# include <fstream>
# include <sstream>

class BitcoinExchange
{
    private:
        std::string                         _file;
        std::string                         _db_file;
        std::map<std::string, float>  _db;

    public:
        BitcoinExchange(std::string file);
        BitcoinExchange(BitcoinExchange const & b);
        ~BitcoinExchange();

        BitcoinExchange &   operator=(BitcoinExchange const & b);
        bool                setup();
        void                evaluate();

    private:
        BitcoinExchange();
        bool    isValidDate(std::string const & dateStr);
        bool    isValidPercentage(std::string const & per);
        bool    isValidValue(std::string const & value);

};

#endif