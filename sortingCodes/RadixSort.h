#ifndef RADIX_SORT_H
#define RADIX_SORT_H


int getMax(int *e, int size);
void countSort(int *e, int size, int exp);


void RadixSort(int *e, int size)
{
    // Find the maximum number to determine the number of digits
    int m = getMax(e, size);

    // Perform counting sort for each digit. Exp is 10^i where i is the current digit.
    for(int exp = 1; m / exp > 0; exp *= 10)
        countSort(e, size, exp);
}


int getMax(int *e, int size)
{
    // Find the maximum element in the array
    int mx = e[0];
    for(int i = 1; i < size; i++)
        if(e[i] > mx)
            mx = e[i];
    return mx;
}


void countSort(int *e, int size, int exp)
{
    // Output array to store sorted elements
    int output[size];
    // Initialize count array to store occurrences of digits (0-9)
    int count[10] = {0};

    // Count occurrences of each digit at the current position (exp)
    for(int i = 0; i < size; i++)
        count[(e[i] / exp) % 10]++;

    // Update count[i] to store the position of the next occurrence of each digit
    for(int i = 1; i < 10; i++)
        count[i] += count[i - 1];

    // Build the output array by placing elements in their correct positions
    for(int i = size - 1; i >= 0; i--)
    {
        output[count[(e[i] / exp) % 10] - 1] = e[i];
        count[(e[i] / exp) % 10]--;
    }

    // Copy the sorted elements back into the original array
    for(int i = 0; i < size; i++)
        e[i] = output[i];
}


#endif