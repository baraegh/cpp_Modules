

#ifndef ITER_HPP
# define ITER_HPP

# include <iostream>

template <typename T>
void    printValue(T const & arr)
{
    std::cout << arr << std::endl;
}

template <typename T>
void    iter(T *arr, size_t len, void (*fun)(T const & arr))
{
    for (size_t i = 0; i < len; i++)
        fun(arr[i]);
}

#endif