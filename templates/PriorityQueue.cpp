#include "../headers/PriorityQueue.hpp"
#include <algorithm>
#include <cassert>

template <typename T, typename Container, typename Compare>
PriorityQueue<T, Container, Compare>::PriorityQueue()
    : container_()
    , compare_()
{}

template <typename T, typename Container, typename Compare>
PriorityQueue<T, Container, Compare>::PriorityQueue(const PriorityQueue& rhv)
    : container_(rhv.container_)
    , compare_(rhv.compare_)
{}

template <typename T, typename Container, typename Compare>
PriorityQueue<T, Container, Compare>::PriorityQueue(const pointer first, const pointer last, const Compare& compare)
    : container_(first, last), compare_(compare)
{
    std::make_heap(container_.begin(), container_.end(), compare_);
}


template <typename T, typename Container, typename Compare>
PriorityQueue<T, Container, Compare>::PriorityQueue(const Compare& rhv)
    : container_()
    , compare_(rhv)
{}

template <typename T, typename Container, typename Compare>
PriorityQueue<T, Container, Compare>&
PriorityQueue<T, Container, Compare>::operator=(const PriorityQueue& rhv)
{
    if (this == &rhv) return *this;

    container_ = rhv.container_;
    compare_ = rhv.compare_;
    return *this;
}

template <typename T, typename Container, typename Compare>
bool
PriorityQueue<T, Container, Compare>::empty() const
{
    return container_.empty();
}

template <typename T, typename Container, typename Compare>
typename PriorityQueue<T, Container, Compare>::const_reference
PriorityQueue<T, Container, Compare>::top() const
{
    return container_.front();
}

template <typename T, typename Container, typename Compare>
void
PriorityQueue<T, Container, Compare>::push(const_reference value)
{
    container_.push_back(value);
    std::push_heap(container_.begin(), container_.end(), compare_);
}

template <typename T, typename Container, typename Compare>
void
PriorityQueue<T, Container, Compare>::pop()
{
    std::pop_heap(container_.begin(), container_.end(), compare_);
    container_.pop_back();
}

template <typename T, typename Container, typename Compare>
typename PriorityQueue<T, Container, Compare>::size_type
PriorityQueue<T, Container, Compare>::size() const
{
    return container_.size();
}
