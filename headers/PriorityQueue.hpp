#ifndef __PRIORITY_QUEUE_HPP__
#define __PRIORITY_QUEUE_HPP__

#include <vector>

template <typename T, typename Container = std::vector<T>, typename Compare = std::less<typename Container::value_type> >
class PriorityQueue
{
public:
    typedef T                                       value_type;
    typedef T*                                      pointer;
    typedef Container                               container_type;
    typedef Compare                                 value_compare;
    typedef typename Container::size_type           size_type;
    typedef typename Container::reference           reference;
    typedef typename Container::const_reference     const_reference;

public:
    PriorityQueue();
    PriorityQueue(const PriorityQueue& rhv);
    PriorityQueue(const Compare& rhv);
    PriorityQueue(const pointer first, const pointer last, const Compare& compare = Compare());

    PriorityQueue& operator=(const PriorityQueue& rhv);

    const_reference top() const;
    void push(const_reference value);
    void pop();

    bool empty()     const;
    size_type size() const;

private:
    container_type container_;
    value_compare compare_;
};

#include "../templates/PriorityQueue.cpp"

#endif ///__PRIORITY_QUEUE_HPP__
