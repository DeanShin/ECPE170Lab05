// Based on:
// http://csapp.cs.cmu.edu/public/ics2/code/opt/vec.h
// Computer Systems: A Programmer's Perspective
// Chapter 5: Optimizing Program Performance

#ifndef VEC_H
#define VEC_H

// Create abstract data type for vector
typedef struct {
    long int len;
    data_t *data;
    long int allocated_len;
} vec_rec, *vec_ptr;

// Create vector
vec_ptr new_vec(long int len);

// Fill vector with initial values
void init_vec(vec_ptr ptr);

// Free vector
void free_vec(vec_ptr ptr);

// Retrieve vector element and store in dest.
// Return 0 (out of bounds) or 1 (successful)
int get_vec_element(vec_ptr v, long int index, data_t *dest);

// Get vector length
long int vec_length(vec_ptr v);

#endif // VEC_H
