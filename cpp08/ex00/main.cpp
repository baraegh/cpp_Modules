
#include "easyfind.hpp"
#include <vector>
#include <iterator>
#include <list>
#include <deque>

int main()
{
    std::cout << "------- vector ------" << std::endl;
    std::vector<int> v;

    for (int i = 0; i <= 20; i++)
    {
        v.push_back(i);
    }
     
	for (std::vector<int>::iterator it = v.begin(); it != v.end(); ++it)
		std::cout << *it << ' ';

	std::cout << std::endl;

	try
	{
		easyFind(v, 6);
		easyFind(v, 21);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "\n------- list ------" << std::endl;
    std::list<int> _list;

    for (int i = 0; i <= 10; i++)
    {
        _list.push_back(i);
    }
        
	for (std::list<int>::iterator it = _list.begin(); it != _list.end(); ++it)
		std::cout << *it << ' ';

	std::cout << std::endl;

	try
	{
		easyFind(_list, 5);
		easyFind(_list, 12);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

    std::cout << "\n------- deque ------" << std::endl;
    std::deque<int> dq;

	for (int i = 0; i < 3; i++)
	{
		dq.push_back(i);
		dq.push_front(3 - i);
	}

	for (std::deque<int>::iterator it = dq.begin(); it != dq.end(); ++it)
		std::cout << *it << ' ';
	std::cout << std::endl;

	try
	{
		easyFind(dq, 0);
		easyFind(dq, 5);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	

    return 0;
}