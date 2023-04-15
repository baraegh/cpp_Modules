

#include "PmergeMe.hpp"

PmergeMe::PmergeMe(){}

PmergeMe::PmergeMe(std::string list)
    : _list(list) {}

PmergeMe::PmergeMe(PmergeMe const & p)
{
    *this = p;
}

PmergeMe::~PmergeMe(){}

PmergeMe & PmergeMe::operator=(PmergeMe const & p)
{
    _list = p._list;
    _vector = p._vector;
    _deque = p._deque;
    return *this;
}

bool    PmergeMe::isInteger(std::string nbr)
{
    int                 plus = 0;

    for (size_t j = 0; j < nbr.size(); j++)
    {
        if (nbr[j] == '+' && plus == 0)
        {
            plus = 1;
            continue;
        }
        if (!isdigit(nbr[j]))
        {
            std::cout << "Error: invalid value: " << nbr << '\n';
            return false;
        }
    }
    return true;
}

bool    PmergeMe::insertToCont(std::string const & nbr)
{
    std::istringstream  iss(nbr);
    int                 value;

    if (!(iss >> value))
    {
        std::cout << "Error: invalid value: " << nbr << '\n';
        return false;
    }

    if (value > std::numeric_limits<int>::max())
    {
        std::cout << "Error: invalid value: " << nbr << '\n';
        return false;
    }

    _vector.push_back(value);
    _deque.push_back(value);

    return true;
}

bool    PmergeMe::setup()
{
    size_t              pos = 0;
    size_t              i = 0;
    std::string         nbr;

    while ((pos = _list.find(" ", i)) != std::string::npos)
    {
        if (pos == 0 || _list[pos - 1] == ' ')
        {
            i++;
            continue ;
        }

        nbr = _list.substr(i, pos - i);
        if (!isInteger(nbr))
            return false;
        if (!insertToCont(nbr))
            return false;
        nbr.clear();
        i = pos + 1;
    }

    if (_list[_list.size() - 1] != ' ')
    {
        pos = _list.find_last_of(" ");
        nbr = _list.substr(pos + 1);
        if (!isInteger(nbr))
            return false;
        if (!insertToCont(nbr))
            return false;
    }
    return true;
}

void    PmergeMe::insertion(size_t l)
{
        if (l == 0)
            return ;
        if (_vector[l] < _vector[l - 1])
            std::swap(_vector[l], _vector[l - 1]);
        if (l - 1 != 0)
            insertion(l - 1);
}

void    PmergeMe::merge(size_t l, size_t m, size_t r)
{
    size_t              l_size = m - l + 1;
    size_t              r_size = r - m;
    std::vector<int>    l_vector(l_size);
    std::vector<int>    r_vector(r_size);
    size_t              l_index, r_index, index;

    for (size_t i = 0; i < l_size; i++)
        l_vector[i] = _vector[l + i];
    
    for (size_t i = 0; i < r_size; i++)
        r_vector[i] = _vector[m + i];
    
    l_index = 0;
    r_index = 0;
    index = l;

    while (l_index < l_size && r_index < r_size)
    {
        if (l_vector[l_index] <= r_vector[r_index])
        {
            _vector[index] = l_vector[l_index];
            l_index++;
        }
        else
        {
            _vector[index] = l_vector[r_index];
            r_index++;
        }
        index++;
    }

    while (l_index < l_size)
    {
        _vector[index] = l_vector[l_index];
        l_index++;
        index++;
    }

    while (r_index < r_size)
    {
        _vector[index] = r_vector[r_index];
        r_index++;
        index++;
    }
}

void    PmergeMe::mergeInsertSort(size_t l, size_t r)
{
    int m;

    if (r - l  + 1 <= 10)
        for (size_t i = l ; i <= r; i++)
            insertion(i);
    else
    {
        m = (l + r) / 2;
        mergeInsertSort(l, m);
        mergeInsertSort(m + 1, r);
        merge(l, m, r);
    }
}

void    PmergeMe::DQinsertion(size_t l)
{
    if (l == 0)
        return ;
    if (_deque[l] < _deque[l - 1])
        std::swap(_deque[l], _deque[l - 1]);
    if (l - 1 != 0)
        DQinsertion(l - 1);
}

void    PmergeMe::DQmerge(size_t l, size_t m, size_t r)
{
    size_t              l_size = m - l + 1;
    size_t              r_size = r - m;
    std::vector<int>    l_deque(l_size);
    std::vector<int>    r_deque(r_size);
    size_t              l_index, r_index, index;

    for (size_t i = 0; i < l_size; i++)
        l_deque[i] = _deque[l + i];
    
    for (size_t i = 0; i < r_size; i++)
        r_deque[i] = _deque[m + i];
    
    l_index = 0;
    r_index = 0;
    index = l;

    while (l_index < l_size && r_index < r_size)
    {
        if (l_deque[l_index] <= r_deque[r_index])
        {
            _deque[index] = l_deque[l_index];
            l_index++;
        }
        else
        {
            _deque[index] = l_deque[r_index];
            r_index++;
        }
        index++;
    }

    while (l_index < l_size)
    {
        _deque[index] = l_deque[l_index];
        l_index++;
        index++;
    }

    while (r_index < r_size)
    {
        _deque[index] = r_deque[r_index];
        r_index++;
        index++;
    }
}

void    PmergeMe::DQmergeInsertSort(size_t l, size_t r)
{
    int m;

    if (r - l  + 1 <= 10)
        for (size_t i = l ; i <= r; i++)
            DQinsertion(i);
    else
    {
        m = (l + r) / 2;
        DQmergeInsertSort(l, m);
        DQmergeInsertSort(m + 1, r);
        DQmerge(l, m, r);
    }
}

void    PmergeMe::sort()
{
    clock_t v_start, dq_start;
    clock_t v_end, dq_end;
    double  v_time, dq_time;

    std::cout << "before: ";
    for (std::vector<int>::iterator it = _vector.begin(); it != _vector.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;

    v_start = clock();
    mergeInsertSort(0, _vector.size() - 1);
    v_end = clock();

    dq_start = clock();
    DQmergeInsertSort(0, _deque.size() - 1);
    dq_end = clock();

    std::cout << "after: ";
    for (std::vector<int>::iterator it = _vector.begin(); it != _vector.end(); it++)
        std::cout << *it << " ";
    std::cout << std::endl;

    v_time = (double)(v_end - v_start) / CLOCKS_PER_SEC ;
    dq_time = (double)(dq_end - dq_start) / CLOCKS_PER_SEC ;

    std::cout << "Time to process a range of " << _vector.size()
        << " elements with std::vector : " << std::fixed << v_time << " us\n";
    std::cout << "Time to process a range of " << _deque.size()
        << " elements with std::deque : " << dq_time << " us\n";
}