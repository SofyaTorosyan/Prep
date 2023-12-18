#pragma once

#include <stdexcept>
#include <algorithm>
#include <iterator>
#include <iostream>

template <typename T>
class vector
{
    public:
        class  Iterator
	    {
	        private:
	        	T* m_ptr;

	        public:
	        	Iterator operator++() // ++it
	        	{
	        		return Iterator(++m_ptr);
	        	}

	        	Iterator& operator++(int) // it++
	        	{
	        		T* tmp = m_ptr;
	        		m_ptr++;
	        		return tmp;
	        	}

                Iterator operator+(const int i) // ++it
	        	{
                    Iterator tmp(m_ptr);
	        		return Iterator(tmp.m_ptr + i);
	        	}

                Iterator operator+=(const int i) // ++it
	        	{
                    m_ptr = m_ptr + i;
	        		return m_ptr;
	        	}

                Iterator operator--() // ++it
	        	{
	        		return Iterator(--m_ptr);
	        	}

                Iterator& operator--(int) // it--
	        	{
	        		T* tmp = m_ptr;
	        		m_ptr--;
	        		return tmp;
	        	}

                Iterator operator-(const int i)
	        	{
                    Iterator tmp(m_ptr);
	        		return tmp - i;
	        	}
                
                Iterator operator-=(const int i) 
	        	{
                    m_ptr = m_ptr - i;
	        		return m_ptr;
	        	}

	        	Iterator(T* ptr) : m_ptr(ptr)
	        	{

	        	}

	        	T operator*()
	        	{
	        		return *m_ptr;
	        	}

                bool operator<(Iterator& it)
                {
                    return m_ptr < it.m_ptr;
                }

                bool operator>(Iterator& it)
                {
                    return !(m_ptr < it.m_ptr);
                }

                bool operator>=(Iterator& it)
                {
                    return !(m_ptr < it.m_ptr);
                }

                bool operator==(Iterator& it)
                {
                    return !(m_ptr < it.m_ptr) && !(m_ptr > it.m_ptr);
                }
	    };
    public:
        vector() noexcept
        :   m_size(0),
	        m_capacity(0),
	        m_data(nullptr)
        {

        }

        explicit vector(const int size, const T& value = T())
        : m_size(size),
	      m_capacity(size),
	      m_data(new T[m_size]) /// what will be if exception throws--> nothing??
        {
            std::fill(m_data, m_data + m_size, value);
        }

        vector(const std::initializer_list<T>& list) 
        :   m_size(list.size()),
            m_capacity(list.size()),
            m_data(new T[m_size])
        {
            std::copy(list.begin(), list.begin() + m_size, m_data);
        }

        vector(const vector<T>& other) 
        :
	        m_size(other.m_size),
	        m_capacity(other.m_capacity),
            m_data(new T[m_capacity])
        {   
            std::copy(other.m_data, other.m_data + m_capacity, m_data);
        }

        friend void swap(vector<T>& left, vector<T>& right) 
        {
            std::swap(left.m_capacity, right.m_capacity);
            std::swap(left.m_size, right.m_size);
            std::swap(left.m_data, right.m_data);
        }

        vector& operator=(vector<T> other)
        {
           swap(*this, other);
           return *this;
        }

        void push_back(const T& val)  // keep exception safety
        { 
            if (m_size == m_capacity) {
                int cap = m_capacity;
                cap = cap == 0 ? ++cap : cap *= 2;
            	T* tmp(m_data);
            	m_data = new T[cap];
                m_capacity = cap;
                std::copy(tmp, tmp + m_size, m_data);
            	delete[] tmp;
            }
        	m_data[m_size++] = val;
        }

        void reserve(const int cap) {
            if (cap <= m_capacity)
            {
                return;
            }
        	T* tmp(m_data);
        	m_data = new T[cap];
            m_capacity = cap;
            std::copy(tmp, tmp + m_size, m_data);
        	delete[] tmp;
        }

        void print() const 
        {
            std::cout << "size: "     << m_size     << std::endl;
            std::cout << "capacity: " << m_capacity << std::endl;
            std::cout << "data: ";
        	copy(m_data, m_data + m_size, std::ostream_iterator<T>(std::cout, " "));
        	std::cout << std::endl;
        }

        int size() const noexcept
        {
            return m_size;
        }

        int capacity() const noexcept
        {
            return m_capacity;
        }
        
        T& operator[](const int index) const {
	        if (index >= m_size) {
	    	    throw std::out_of_range{"index is out of range"};
	        }
	        return m_data[index];
        }

        Iterator begin() const noexcept
        {
            return Iterator(m_data);
        }

        Iterator end() const noexcept
        {
            return Iterator(m_data + m_size);
        }

        bool empty() const noexcept
        {
            return m_size == 0;
        }

        /*
        void resize(const int count)
        {
            if (count == m_size) 
            {
                return;
            }
            if (count < m_size)
            {
                m_size = count;
                return;
            }
            // if count > m_size
            if (count >= m_capacity)
            {
                m_capacity *= 2;
                vector<T> temp(count);
                std::copy(m_data, m_data + m_size, temp.m_data);
                swap(temp, *this);
            }
        }
        */

        void clear() noexcept
        {
            m_size = 0;
        }
        
        /*
        Iterator insert(Iterator pos, const int value)
        {
            if (pos < begin() || pos > end())
            {
                throw std::out_of_range("position is out of range");
            }
            if ((m_size + 1 )> m_capacity) // reallocate memory
            {
                vector<T> tmp((m_size + 1));
                std::copy(m_data, m_data + pos, tmp.m_data);
                tmp[pos] = value;
                std::copy(m_data + pos + 1, m_data + m_size + 1, tmp.m_data + m_data + pos + 1);
                swap(tmp, *this);
            }
            // if((m_size + 1 ) < m_capacity)
            // {
            //     std::copy(m_data, m_data + pos, tmp.m_data);
            //     tmp[pos] = value;
            //     std::copy(m_data + pos + 1, m_data + m_size + 1, tmp.m_data + m_data + pos + 1);
            // }
        }
        */

    private:
        int m_size;
        int m_capacity;
        T* m_data;
};
