

# include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange(std::string file)
    : _file(file), _db_file("data.csv")
{}

BitcoinExchange::BitcoinExchange(BitcoinExchange const & b)
{
    *this = b;
}

BitcoinExchange::~BitcoinExchange(){}

BitcoinExchange &   BitcoinExchange::operator=(BitcoinExchange const & b)
{
    _file = b._file;
    _db_file = b._db_file;
    return *this;
}

bool    BitcoinExchange::isValidDate(std::string const & dateStr)
{
    std::istringstream  iss(dateStr);
    int                 y, m, d;
    char                delm1, delm2;

    if (!(iss >> y >> delm1 >> m >> delm2 >> d))
        return false;

    if (!iss.eof())
        return false;

    if (delm1 != '-' || delm2 != '-')
        return false;
    
    if (y < 0 || y > 2023 || m < 1 || m > 12 || d < 1 || d > 31)
        return false;
    
    if (d > 30 && (m == 4 || m == 6 || m == 9 || m == 11))
        return false;
    
    if (m == 2 && ((y % 4 == 0 && y % 100 != 0) || y % 400 == 0) && d > 29)
        return false;

    if (m == 2 && (!((y % 4 == 0 && y % 100 != 0) || y % 400 == 0)) && d > 28)
        return false;

    if (d > 29 && m == 2)
        return false;
    
    return true;
}

bool    BitcoinExchange::setup()
{
    if (access(_db_file.c_str(), F_OK | R_OK) == 0)
    {
        std::ifstream       file(_db_file);
        std::string         line;
        std::string         date;
        std::string         per;
        size_t              pos;
        float               fPer;

        std::getline(file, line);
        if (line != "date,exchange_rate")
            return false;
        while (std::getline(file, line))
        {
            if ((pos = line.find(",")) != std::string::npos)
            {
                date = line.substr(0, pos);
                per = line.substr(pos + 1);
                std::stringstream   ss(per);

                if (!isValidDate(date))
                    return false;
                ss >> fPer;
                _db.insert(std::make_pair(date, fPer));
                date.clear();
                per.clear();
            }
            else
                return false;
        }
        return true;
    }
    return false;
}

bool    BitcoinExchange::isValidValue(std::string const & value)
{
    std::istringstream      iss(value);
    float                   nbr;

    if (iss >> nbr && iss.eof() && nbr >= 0 && nbr <= 1000)
        return true;
    return false;
}

void    BitcoinExchange::evaluate()
{
    std::ifstream   file(_file);
    std::string     line;
    std::string     date;
    std::string     value;
    size_t          pos;
    size_t          i;
    float           nbr;

    std::getline(file, line);
    if (line != "date | value")
        std::cout << "Error: input's header is invalid\n";
    
    while (std::getline(file, line))
    {
        if ((pos = line.find(" | ")) != std::string::npos)
        {
            date = line.substr(0, pos);
            value = line.substr(pos + 3);

            if (!isValidDate(date))
            {
                std::cout << "Error: invalid date format => " << date << '\n';
                continue;
            }

            if ((i = value.find(",")) != std::string::npos)
                value[i] = '.';

            if (!isValidValue(value))
            {
                value[i] = ',';
                std::cout << "Error: invalid value => " << value << '\n';
                continue;
            }

            if (_db.find(date) != _db.end())
                std::cout << date << " => " << value << " = " << _db[date] << '\n';
            else
            {
                std::map<std::string, float>::iterator    it = _db.lower_bound(date);
                if (it != _db.begin())
                {
                    std::stringstream   ss(value);
                    
                    ss >> nbr;
                    it--;
                    std::cout << date << " => " << value << " = " << std::fixed << nbr * (*it).second << '\n';
                }
                else
                    std::cout << "Error: date out of range => " << date << '\n';
            }
            
        }
        else
            std::cout << "Error: bad input => " << line << '\n';
    }
}

BitcoinExchange::BitcoinExchange(){}