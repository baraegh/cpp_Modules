

#ifndef ARRAY_HPP
# define ARRAY_HPP

template <typename T>
class Array
{
    private:
        unsigned int    _len;
        T               *_arr;
        
    public:
        Array()
            : _len(0), _arr(new T[_len]){}

        Array(unsigned int n)
            : _len(n), _arr(new T[_len]){}

        Array(Array const & arr)
        {
            *this = arr;
        }

        Array & operator=(Array const & arr)
        {
            this->_len = arr._len;
            delete this->_arr;
            if (arr._arr)
            {
                this->_arr = new T[this->_len];
                for (unsigned int i = 0; i < this->_len; i++)
                    this->_arr[i] = arr._arr[i];
            }
            else
                this->_arr = NULL;
            return *this;
        }

        T & operator[](int index)
        {
            if (index < 0 || (unsigned int)index >= this->_len)
                throw IndexOutOfBounds();
            return this->_arr[index];
        }

        unsigned int    size() const
        {
            return this->_len;
        }

        ~Array()
        {
            // delete [] this->_arr;
        }

        class   IndexOutOfBounds : public std::exception
        {
            public:
                const char* what() const throw()
                {
                    return "index out of bounds";
                }
        };
};



#endif