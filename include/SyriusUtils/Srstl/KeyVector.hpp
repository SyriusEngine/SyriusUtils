#pragma once

#include <SyriusUtils/Logger/Conditions.hpp>

#include <vector>
#include <unordered_map>

namespace Srstl {

    template<typename K, typename D>
    class KeyVector {
    public:
        KeyVector() = default;

        explicit KeyVector(std::size_t size) {
            m_Data.reserve(size);
        }

        ~KeyVector() = default;

        void insert(const K &key, const D &data) {
            SR_PRECONDITION(m_KeyIndexMap.find(key) == m_KeyIndexMap.end(), "[KeyVector]: Key {} already exists", key)

            m_Data.push_back(data);
            m_KeyIndexMap.insert({key, m_Data.size() - 1});
        }

        template<typename... Args>
        void emplace(const K &key, Args &&... args) {
            SR_PRECONDITION(m_KeyIndexMap.find(key) == m_KeyIndexMap.end(), "[KeyVector]: Key {} already exists", key)

            m_Data.emplace_back(std::forward<Args>(args)...);
            m_KeyIndexMap.insert({key, m_Data.size() - 1});
        }

        const D &get(const K &key) const {
            SR_PRECONDITION(m_KeyIndexMap.find(key) != m_KeyIndexMap.end(), "[KeyVector]: cannot retrieve element, key "
                                                                            "{} does not exists", key);

            return m_Data[m_KeyIndexMap[key]];
        }

        D &get(const K &key) {
            SR_PRECONDITION(m_KeyIndexMap.find(key) != m_KeyIndexMap.end(), "[KeyVector]: cannot retrieve element, "
                                                                            "key {} does not exists", key);

            return m_Data[m_KeyIndexMap[key]];
        }

        const D &operator[](const K &key) const {
            SR_PRECONDITION(m_KeyIndexMap.find(key) != m_KeyIndexMap.end(),
                            "[KeyVector]: cannot retrieve element, key {} does not exists", key);

            return m_Data[m_KeyIndexMap[key]];
        }

        D &operator[](const K &key) {
            SR_PRECONDITION(m_KeyIndexMap.find(key) != m_KeyIndexMap.end(),
                            "[KeyVector]: cannot retrieve element, key {} does not exists", key);

            return m_Data[m_KeyIndexMap[key]];
        }

        void remove(const K &key) {
            SR_PRECONDITION(m_KeyIndexMap.find(key) != m_KeyIndexMap.end(),
                            "[KeyVector]: cannot remove element, key {} does not exists", key);

            auto lastDataIndex = m_Data.size() - 1;
            auto currentDataIndex = m_KeyIndexMap[key];
            K lastElementKey;
            for (const auto &lastKey: m_KeyIndexMap) {
                if (lastDataIndex == lastKey.second) {
                    lastElementKey = lastKey.first;
                    break;
                }
            }
            // switch last and current element from place
            // make sure to move the object!
            auto swapped = std::move(m_Data[lastDataIndex]);
            auto toDestroy = std::move(m_Data[currentDataIndex]);
            m_Data[currentDataIndex] = std::move(swapped);
            m_Data[lastDataIndex] = std::move(toDestroy);

            // and delete the last element
            m_Data.pop_back();
            m_KeyIndexMap.erase(key);
            // update index
            m_KeyIndexMap[lastElementKey] = currentDataIndex;
        }

        auto begin() {
            return m_Data.begin();
        }

        auto begin() const {
            return m_Data.begin();
        }

        auto end() {
            return m_Data.end();
        }

        auto end() const {
            return m_Data.end();
        }

        bool has(const K &key) const {
            return m_KeyIndexMap.find(key) != m_KeyIndexMap.end();
        }

        [[nodiscard]] size_t getSize() const {
            return m_Data.size();
        }

        const std::vector<D> &getData() const {
            return m_Data;
        }

    private:
        std::vector<D> m_Data;
        std::unordered_map<K, Size> m_KeyIndexMap;
    };

}