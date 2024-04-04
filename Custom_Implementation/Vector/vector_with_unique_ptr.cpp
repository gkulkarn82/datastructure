/*
Implement own vector class that has following features
1.Default constructor
2.Parameterised constructor
3.Copy constructor
4.Copy assignment operator
5.Move Constructor
6.Move Assignment Operator
7.Reserve
8.push_back
9.capacity
10.size
11.[] (subscript) operator
*/

#include<iostream>

namespace own
{
    const unsigned short DEFAULT_CAPACITY = 5;
    template<typename T>
    class vector
    {
        public:
            explicit vector(const std::size_t& size = 0,const T& value= T{}) noexcept
                :_size(size),
                _capacity(size == 0 ? DEFAULT_CAPACITY : size),
                _ptr(std::make_unique<T[]>(_capacity))
            {
                for(std::size_t i = 0 ; i < _size; ++i)
                {
                    _ptr[i] = value;
                }
            }

            ~vector() noexcept
            {}

            //copy constructor
            vector(const vector& source) noexcept
                :_size(source.size),
                _capacity(source.capacity),
                _ptr(std::make_unique<T[]>(_capacity))
            {
                for(std::size_t i = 0 ; i < _size; ++i)
                {
                    _ptr[i] = source[i];
                }
            }           

            //copy assignment operator
            vector& operator=(const vector& source)
            {
                if(this != &source)
                {
                    vector temp(source)
                    this->swap(temp);
                }
                return *this;
            }

            //move constructor
            vector(const vector&& source) noexcept
                :_size(std::move(source.size)),
                _capacity(std::move(source.capacity)),
                _ptr(std::move(source._ptr))
            {
                source.size = 0;
                soruce.capacity = 0;
            }           

            //move assignment operator
            vector& operator=(const vector&& source) noexcept
            {
                if(this != &source)
                {
                    vector temp(std::move(source))
                    this->swap(temp);
                }
                return *this
            }

            void reserve(const std::size_t& noOfElements) noexcept
            {
                if(_capacity >= noOfElements)
                {
                    return;
                }
                reallocate(noOfElements);
            }

            void push_back(const T& value) noexcept
            {
                if(_size >= _capacity)
                    reallocate(_size + DEFAULT_CAPACITY);
                _ptr[size] = value;
                ++_size;
            }

            std::size_t capacity() const noexcept
            {
                return _capacity;
            }

            std::size_t size() const noexcept
            {
                return _size;
            }

            T& operator[](T& index)
            {
                return _ptr[index]; //ask once again why returning reference
            }

            const T& operator[](T& index) const
            {
                return _ptr[index];
            }

            void print()
            {
                for(std::size_t i = 0 ; i < _size; ++i)
                {
                    std::cout << _ptr[i] << " ";
                }
                std::cout << endl;
            }

        private:

            void swap(const vector& source) noexcept
            {
                std::swap(this->_size, source->_size);
                std::swap(this->_capacity, source->_capacity);
                std::swap(this->_ptr, source->_ptr);
            }

            void reallocate(const std::size_t& noOfElements) noexcept
            {
                std::unique_ptr<T[]> temp = std::make_unique<T[]>(noOfElements);
                for(std::size_t i = 0 ; i < _size; ++i)
                {
                    temp[i] = _ptr[i]
                }
                _ptr.swap(temp);
                _capacity = noOfElements;
            }

            std::size_t _size;
            std::size_t _capacity;
            std::unique_ptr<T[]> _ptr;
    };

}

template <typename T>
void PrintStatistics(own::vector<T>& vect)
{
    std::cout << "Capacity : " << vect.capacity << " Size: " << vect.size << " " << endl;
    vect.print();
}

int main()
{
    own::vector<int> vect;
    PrintStatistics(vect);
    vect.reserve(10);
    PrintStatistics(vect);

    vect.push_back(1);
    vect.push_back(2);
    PrintStatistics(vect);

    std::cout<< "Copy constructor" << endl;
    own::vector<int> vect1 = vect;
    PrintStatistics(vect1);
    PrintStatistics(vect);

    std::cout<< "Move constructor" << endl;
    own::vector<int> vect2 = std::move(vect);
    PrintStatistics(vect2);
    PrintStatistics(vect);

    std::cout<< "Copy Assignement" << endl;
    vect = vect1;
    PrintStatistics(vect1);
    PrintStatistics(vect);

    std::cout<< "Move Assignement" << endl;
    vect = std::move(vect2);
    PrintStatistics(vect2);
    PrintStatistics(vect);

}