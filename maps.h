//
// Created by MikoG on 31.12.2022.
//

#ifndef NATIVEBETA_MAPS_H
#define NATIVEBETA_MAPS_H

#include "allocator_lists.h"

template<class __Key, class __Type, typename __Size_type> class list
        : protected __Allocate {
    typedef unsigned long long uint64_t;
    typedef long long           int64_t;
    typedef unsigned long      uint32_t;
    typedef long                int32_t;
    typedef unsigned short     uint16_t;
    typedef short               int16_t;
    typedef unsigned char       uint8_t;
    typedef char                 int8_t;

    typedef __Key            index_type;
    typedef __Type            core_type;
    typedef __Size_type          size_s;

    typedef __Allocator<__Key, __Type, __Size_type> core;

    core *alloc;
public:
    int test(index_type index, core_type core, size_s size) {
        alloc->__treat_segment = alloc->stack;
        alloc->__treat_type_alloc = alloc->linear;

        alloc = __Allocate_map_memory(alloc, size);

        fprintf(stdout, "size index array: %p\n", alloc->Index_stack);
        fprintf(stdout, "size core array: %p\n", alloc->Core_stack);

        return alloc->__core_error_treat;
    }
};

#endif //NATIVEBETA_MAPS_H
