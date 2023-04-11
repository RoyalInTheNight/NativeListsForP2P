//
// Created by MikoG on 31.12.2022.
//

#ifndef NATIVEBETA_ALLOCATOR_LISTS_H
#define NATIVEBETA_ALLOCATOR_LISTS_H

#include <iostream>
#include <exception>
#include <string>
#include "core.h"

namespace ptr = core_maps::ptr;

template<class key_t, class type_t> class Allocator_elem {
private:
    static key_t  * key_ptr;
    static type_t *type_ptr;

public:
    static Allocator_elem &init_data(key_t& index, type_t& type) {
        if (key_ptr == nullptr || type_ptr == nullptr)
            throw std::runtime_error("error allocate memory in heap\n");

        *key_ptr = std::move(index);
        *type_ptr = std::move(type);
    }

    key_t&  get_key()  {return *key_ptr; }
    type_t& get_elem() {return *type_ptr;}

    ~Allocator_elem() {delete key_ptr; delete type_ptr;}
};

#endif //NATIVEBETA_ALLOCATOR_LISTS_H