#include "function_pointers.h"
#include <stdio.h>

/**
 * int_index - Function that searches for integer
 * @array: Points to array of integers
 * @size: Number of array elements
 * @cmp: Function pointer to compare values
 * Return: First element index
 */

int int_index(int *array, int size, int (*cmp)(int))
{
	  int x;
	  
	  if (array && cmp)
	  {
		  for (x = 0; x < size; x++)
		  {
			  if (cmp(array[x]) != 0)
				  return (x);
		  }
	  }
	  
	  return (-1);
}
