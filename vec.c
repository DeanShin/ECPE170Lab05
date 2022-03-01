// http://csapp.cs.cmu.edu/public/ics2/code/opt/vec.c
// Computer Systems: A Programmer's Perspective
// Chapter 5: Optimizing Program Performance

#include <stdlib.h>
#include <stdio.h>
#include "config.h"
#include "vec.h"

// Create vector of specified length
vec_ptr new_vec(long int len)
{
  double total_bytes_to_alloc = sizeof(vec_rec) + sizeof(data_t)*len;
  printf("Allocating %.2f MB for vector storage\n", total_bytes_to_alloc/1024/1024);

  // Allocate header structure
  vec_ptr result = (vec_ptr) malloc(sizeof(vec_rec));
  if (!result)
    return NULL;  /* Couldn't allocate storage */
  result->len = len;

  result->allocated_len = len;

  // Allocate array
  if (len > 0) {
    data_t *data = (data_t *)calloc(len, sizeof(data_t));
    if (!data) {
      free((void *) result);
      return NULL; /* Couldn't allocate storage */
    }
    result->data = data;
  }
  else
    result->data = NULL;
  return result;
}

// Fill vector with initial values
void init_vec(vec_ptr v)
{
  long int i;
  data_t value=1;
  long int length = vec_length(v);

  for(i=0; i < length; i++)
    {
      v->data[i] = value;
      value++;
    }
}

// Free vector
void free_vec(vec_ptr ptr)
{
  printf("Freeing vector from memory\n");
  free(ptr->data);
  free(ptr);
  ptr = NULL;
}


// Retrieve vector element and store at dest.
// Return 0 (out of bounds) or 1 (successful)
int get_vec_element(vec_ptr v, long int index, data_t *dest)
{
  if (index < 0 || index >= v->len)
    return 0;
  *dest = v->data[index];
  return 1;
}

// Return length of vector
long int vec_length(vec_ptr v)
{
    return v->len;
}


