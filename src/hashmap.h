#pragma once

namespace nstd
{
    template <typename KeyType, typename ValueType>
    struct hashmap 
    {
    public:
        hashmap() = default;

        bool exist(const KeyType& key) {};

        void put(const KeyType& key, const ValueType value) {};
        
        ValueType& get(const KeyType& key) {};
        
        void remove(const KeyType& key) {};

    private:
        static constexpr unsigned long long k_max_elements_size = (1 << 32) - 1;
        KeyType* m_keys;
        ValueType* m_values;
    };
}