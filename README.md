# PriorityQueue

The `PriorityQueue` class implements a **priority queue** data structure using a customizable underlying container and comparator.  
It ensures that the element with the highest priority (according to the comparator) is always accessible at the top.

This is a **template class** and can work with any container that supports random-access iterators (like `std::vector` or `std::deque`) and standard heap operations.

---

## Key Features

- **Template Class:** `PriorityQueue<T, Container, Compare>` can store any type of data `T` with a customizable container and comparison function.
- **Heap-Based Implementation:** Uses standard C++ heap operations (`make_heap`, `push_heap`, `pop_heap`) for efficient priority management.
- **Element Access:** `top()` returns the element with the highest priority.
- **Modifiers:** `push()` adds an element, maintaining heap order; `pop()` removes the highest-priority element.
- **Utility Functions:** `empty()` and `size()` to inspect the queue state.

---

## Usage Example

```cpp
#include "PriorityQueue.hpp"
#include <vector>
#include <functional>
#include <iostream>

int main() {
    // Max-heap using std::less
    PriorityQueue<int, std::vector<int>, std::less<int>> pq;

    // Add elements
    pq.push(10);
    pq.push(30);
    pq.push(20);

    // Print top element
    std::cout << "Top element: " << pq.top() << std::endl; // 30

    // Remove top element
    pq.pop();
    std::cout << "After pop, top element: " << pq.top() << std::endl; // 20

    // Check size
    std::cout << "PriorityQueue size: " << pq.size() << std::endl; // 2

    // Check if empty
    if (!pq.empty()) {
        std::cout << "PriorityQueue is not empty." << std::endl;
    }

    return 0;
}
