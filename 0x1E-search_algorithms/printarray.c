#include "search_algos.h"

/**
 * print_array - Prints the elements of an array within a given range.
 * @array: Pointer to the first element of the array.
 * @start: Starting index to print.
 * @end: Ending index to print.
 */
void print_array(int *array, size_t start, size_t end)
{
    printf("Searching in array: ");
    for (; start <= end; start++)
    {
        printf("%d", array[start]);
        if (start < end)
            printf(", ");
    }
    printf("\n");
}
