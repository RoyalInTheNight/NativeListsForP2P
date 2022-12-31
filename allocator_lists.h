//
// Created by MikoG on 31.12.2022.
//

#ifndef NATIVEBETA_ALLOCATOR_LISTS_H
#define NATIVEBETA_ALLOCATOR_LISTS_H

class __Allocate {
protected:
    // core
    const int OK                     =  0;
    const int INVALID_ALLOCATE_STACK = -1;
    const int ALLOCATE_SIZE_ERROR    = -2;

    template<class __Key, class __Type, typename __Size_type> struct __Allocator {
        __Key         *Index_heap;
        __Type         *Core_heap;

        __Key        *Index_stack;
        __Type        *Core_stack;

        __Size_type        offset;
        __Size_type          size;
        __Size_type    size_alloc;

        enum type_alloc {
            interpreter = 0,
            linear
        };

        enum segment {
            stack = 2,
            heap
        };

        int       __treat_segment;
        int    __treat_type_alloc;

        int    __core_error_treat;
    };

    template<class __Key, class __Type, typename __Size_type> __Allocator<__Key, __Type, __Size_type> *
    __Allocate_map_memory(__Allocator<__Key, __Type, __Size_type> *core_allocate, __Size_type size) {
        if (core_allocate->__treat_type_alloc == core_allocate->linear) { // linear allocate
            if (size == 0) {
                core_allocate->__core_error_treat = ALLOCATE_SIZE_ERROR;

                return core_allocate;
            }

            else if (core_allocate->__treat_segment == core_allocate->stack) {
                if (sizeof(__Key) == 8 ||
                    sizeof(__Type) == 8) {
                    core_allocate->__core_error_treat = INVALID_ALLOCATE_STACK;

                    return core_allocate;
                }

                else {
                    core_allocate->size = size;

                    __Key StackIndexArray[core_allocate->size];
                    __Type StackCoreArray[core_allocate->size];

                    core_allocate->Index_stack = StackIndexArray;
                    core_allocate->Core_stack = StackCoreArray;
                    core_allocate->__core_error_treat = OK;

                    return core_allocate;
                }
            }

            else if (core_allocate->__treat_segment == core_allocate->heap) {
                core_allocate->size = size;

                __Key *HeapIndexArray = new __Key[core_allocate->size];
                __Type *HeapCoreArray = new __Type[core_allocate->size];

                core_allocate->Index_heap = HeapIndexArray;
                core_allocate->Core_heap = HeapCoreArray;
                core_allocate->__core_error_treat = OK;

                return core_allocate;
            }
        }

        // interpreter allocate in develop...
    };
};

#endif //NATIVEBETA_ALLOCATOR_LISTS_H
