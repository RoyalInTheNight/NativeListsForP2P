//
// Created by MikoG on 11.04.2023.
//

#ifndef NATIVELISTSFORP2P_CORE_H
#define NATIVELISTSFORP2P_CORE_H

namespace core_maps {
    typedef char                 int8_t;
    typedef unsigned char       uint8_t;
    typedef short               int16_t;
    typedef unsigned short     uint16_t;
    typedef int                 int32_t;
    typedef unsigned int       uint32_t;
    typedef long long           int64_t;
    typedef unsigned long long uint64_t;

    typedef float             float32_t;
    typedef double            float64_t;

    typedef void                empty_t;
    typedef void *             memory_t;

    namespace ptr {
        typedef core_maps::int32_t    size_t;
    }

    namespace type_id {
        const static core_maps::int8_t *char_t = "Pc";
    }
}

#endif //NATIVELISTSFORP2P_CORE_H
