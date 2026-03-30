//
// Created by lejan on 3/24/2026.
//

#ifndef ARRAYSTACK_H
#define ARRAYSTACK_H

#include <vector>
#include <stdexcept>

template <typename T>
class ArrayStack {
private:
    std::vector<T> data;

public:
    void push(const T& value) {
        // TODO
        data.push_back(value);
    }

    void pop() {
        // TODO
        if (data.empty()) {
            throw std::runtime_error("Stack Underflow error ArrayStack is empty");
        }
        data.pop_back();
    }

    T top() const {
        // TODO
        if (data.empty()) {
            throw std::runtime_error("Cannot return top element, ArrayStack is empty");
        }
        return data.back();
    }

    bool empty() const {
        // TODO
        return data.empty();
    }

    int size() const {
        // TODO
        return data.size();
    }
};

#endif