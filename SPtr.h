//
// Created by MikoG on 11.04.2023.
//

#ifndef NATIVELISTSFORP2P_SPTR_H
#define NATIVELISTSFORP2P_SPTR_H

#include <iostream>
#include <exception>
#include <string>
#include "core.h"

template<class alloc_t> class SPtr {
private:
    alloc_t         *ptr;
    ptr::size_t size_ptr;

public:
    SPtr(const SPtr<alloc_t>& copy) : ptr(copy.ptr), size_ptr(copy.size_ptr) {}
    SPtr() : ptr(new alloc_t[1]), size_ptr(1) {}

    alloc_t& get() {
        return *ptr;
    }

    alloc_t& operator[](ptr::size_t pos) {
        if (pos >= size_ptr)
            throw std::runtime_error("out of array: " + std::to_string(pos) + " >= " + std::to_string(size_ptr) + "\n");

        return *(ptr + pos);
    }

    core_maps::empty_t add_elem(alloc_t& elem) {
        ptr = new alloc_t[1];
        size_ptr += 1;

        ptr[length()] = elem;
    }

    inline ptr::size_t size() {
        return size_ptr;
    }

    inline ptr::size_t length() {
        return size_ptr - 1;
    }

    ~SPtr() {
        delete[] ptr;
    }
};

#endif //NATIVELISTSFORP2P_SPTR_H
