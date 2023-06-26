
#pragma once

#include <NTL/ZZ.h>

using namespace NTL;

namespace Utils { 

    bool is_palindrome( const ZZ & number );

    ZZ get_reverse( const ZZ & number );

    bool is_lichrel( const ZZ & number, const ushort limit=50 ); 

    size_t get_sum_of_digits( const ZZ & number );
}