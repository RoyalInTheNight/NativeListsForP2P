//
// Created by MikoG on 31.12.2022.
//

#ifndef NATIVEBETA_MAPS_H
#define NATIVEBETA_MAPS_H

#include "allocator_lists.h"
#include "SPtr.h"

template<class Key_t, class Type_t, class allocator = Allocator_elem<Key_t, Type_t>> class pet_map
        : public allocator {
private:
    static SPtr<allocator> map_elems;
    ptr::size_t  control_size;
    ptr::size_t  elem_f_treat;

public:
    pet_map(const pet_map<Key_t, Type_t, allocator>& copy) {
        *this = copy;
    }

    pet_map() : control_size(1), elem_f_treat(0) {}

    static allocator& value_type(Key_t index, Type_t value) {
        allocator init = Allocator_elem<Key_t, Type_t>::init_data(index, value);

        return init;
    }

    static core_maps::empty_t insert(allocator& elem) {
        map_elems.add_elem(elem);
    }

    Type_t at(Key_t index) {
        if (typeid(index).name() == (std::string) core_maps::type_id::char_t) {
            for (ptr::size_t i = 0; i < map_elems.size(); i++) {
                if (map_elems[i].get_key() == (std::string) index)
                    return map_elems[i].get_elem();

                else
                    elem_f_treat++;
            }

            if (elem_f_treat == map_elems.size())
                throw std::runtime_error("pet_map out of range\n");
        }

        else {
            for (ptr::size_t i = 0; i < map_elems.size(); i++) {
                if (map_elems[i].get_key() == index)
                    return map_elems[i].get_elem();

                else
                    elem_f_treat++;
            }

            if (elem_f_treat == map_elems.size())
                throw std::runtime_error("pet_map out of range\n");
        }
    }

    pet_map<Key_t, Type_t, allocator>& operator=(const pet_map<Key_t, Type_t, allocator>& copy) {
        *this = copy;
    }
};

#endif //NATIVEBETA_MAPS_H
