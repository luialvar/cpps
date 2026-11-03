#ifndef ITER_HPP
#define ITER_HPP

#include <cstddef>
//for size_t

//compiler know it is a function because it recieves parameters
//to be able to have cont and not const I made the function as a template
template <typename T, typename F>
void iter(T* array, const std::size_t length, F function) {
    for (std::size_t i = 0; i < length; i++) {
        function(array[i]);
    }
}

#endif
