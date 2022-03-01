// Compile this program:
//  unix>  make
// Run this program:
//  unix>  ./combine_program 1 200000000    (for combine1() with 200,000,000 elements)
//  unix>  ./combine_program 2 200000000    (for combine2() with 200,000,000 elements)
//  etc...

#include <stdlib.h>
#include <stdio.h>
#include <string.h>    // For string comparison
#include <time.h>

#include "config.h"
#include "vec.h"
#include "combine.h"

int main(int argc, char *argv[])
{
  vec_ptr vector;
  data_t result;
  long vector_size;
  clock_t time_start, time_end;

  if( argc != 3)
    {
      printf("Program usage: %s <algorithm-num> <vector-size>\n", argv[0]);
      return 1;
    }

  vector_size=atol(argv[2]);
  printf("Processing vector:\n");
  printf(" * Elements: %ld\n", vector_size);
  printf(" * Data type: %s\n", DATA_NAME);
  printf(" * Operation: %s\n", OP_NAME);

  // Allocate vector in memory
  vector = new_vec(vector_size);
  if(vector == NULL)
    {
      printf("Error: Unable to allocate vector\n");
      return 1;
    }

  // Initialize vector with values
  init_vec(vector);

  // Process the vector with different algorithms
  // (that all produce the same result)
  // based on user input
  time_start = clock();
  if(strcmp(argv[1], "1") == 0)
    combine1(vector, &result);
  else if(strcmp(argv[1], "2") == 0)
    combine2(vector, &result);
  else if(strcmp(argv[1], "3") == 0)
    combine3(vector, &result);
  else if(strcmp(argv[1], "4") == 0)
    combine4(vector, &result);
  else if(strcmp(argv[1], "5x2") == 0)
    combine5x2(vector, &result);
  else if(strcmp(argv[1], "5x3") == 0)
    combine5x3(vector, &result);
  else if(strcmp(argv[1], "6") == 0)
    combine6(vector, &result);
  else
    {
      printf("ERROR: Invalid combine algorithm. Must specifiy 1,2,3,4,5x2,5x3, or 6\n");
      free_vec(vector);
      return 1;
    }
  time_end = clock();

  printf("Finished running combine() operation\n");
  // Don't care about the actual results. The array
  // is so big that surely the calculation has
  // overflowed by now... 
  
  printf("Time for combineN(): %.03f seconds\n", ((double)(time_end - time_start))/CLOCKS_PER_SEC);

  // Clean up memory when finished
  free_vec(vector);
  
  return 0;
}
