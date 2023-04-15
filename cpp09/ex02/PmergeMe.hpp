

#ifndef PMERGEME_HPPP
# define PMERGEME_HPPP

# include <iostream>
# include <string>
# include <vector>
# include <deque>
# include <sstream>
# include <limits>
# include <ctime>


class PmergeMe
{
    private:
        std::string         _list;
        std::vector<int>    _vector;
        std::deque<int>     _deque;

    public:
        PmergeMe();
        PmergeMe(std::string list);
        PmergeMe(PmergeMe const & p);
        ~PmergeMe();

        PmergeMe &  operator=(PmergeMe const & p);
        bool        setup();
        void        sort();
    
    private:
        bool        isInteger(std::string nbr);
        bool        insertToCont(std::string const & nbr);
        void        insertion(size_t l);
        void        merge(size_t l, size_t m, size_t r);
        void        mergeInsertSort(size_t l, size_t r);
        void        DQinsertion(size_t l);
        void        DQmerge(size_t l, size_t m, size_t r);
        void        DQmergeInsertSort(size_t l, size_t r);
};

#endif