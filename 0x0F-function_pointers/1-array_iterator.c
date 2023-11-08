#include "function_pointers.h"
#include <stdio.h>

/**
 * array_iterator - Function that executes function given as element array parameter
 * @array: Pointer to integer variable
 * @size: Array size
 * @action: Pointer to function
 * Return: Void
 */

void array_iterator(int *array, size_t size, void (*action)(int))
{
	  unsigned int x;

	    if (!array || !action)
		        return;
	      for (x = 0; x < size; x++)
		          action(array[x]);
}
