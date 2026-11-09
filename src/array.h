#pragma once

#include <cstdint>
#include <cstdlib>
#include <cassert>

#include <concepts>
#include <initializer_list>

#include <vector>

namespace nstd
{
    template<typename ValueType, std::uint64_t Size>
    struct array
    {
        array() = default;
        array(std::initializer_list<ValueType> initializer_list)
        {
            assert(initializer_list.size() <= Size);

            auto _First = initializer_list.begin();
            auto _Last = initializer_list.end();

            auto _Myfirst = begin();
            auto _Mylast = end();

            auto _Next = _Myfirst;

            for (; _First != _Last && _Next != _Mylast; ++_First, ++_Next)
            {
                *_Next = *_First;
            }

            for (; _Next != _Mylast; ++_Next)
            {
                *_Next = 0;
            }
        }

        std::uint64_t size() const { return m_size; }
        
        ValueType& operator[](const std::uint64_t index)
        { 
            assert(index >= 0);
            assert(index < m_size);

            return m_data[index]; 
        }

        ValueType* begin() { return m_data; }
        ValueType* end()   { return m_data + m_size; }

    private:
        ValueType m_data[Size];
        std::uint64_t m_size = Size;
    };
}