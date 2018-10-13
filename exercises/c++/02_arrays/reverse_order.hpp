#ifndef REVERSE_ORDER_H__
#define REVERSE_ORDER_H__

/**
    Initializes an array of type T values from stdin.

    @param size the size of the array
    @return the pointer to the first element of the vector.
*/
template <typename T>
T* init_array(int size);

/**
    Prints an array of type T values from the last value to the first.

    @param array the pointer to the first element of the array to be printed.
    @param size the size of the array.
    @return nothing.
*/
template <typename T>
void print_array_reverse(T* array, int size);

#endif //REVERSE_ORDER_H

