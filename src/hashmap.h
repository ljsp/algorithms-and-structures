#pragma once

namespace nstd
{
    template <typename T, typename U>
    struct hashmap 
    {
        static constexpr unsigned long long k_max_elements_size = (1 << 32) - 1;
        T* m_keys;
        U* m_values;
    };
}