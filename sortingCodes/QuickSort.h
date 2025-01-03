#ifndef QUICK_SORT_H
#define QUICK_SORT_H


int partition(int *e, int low, int high);


void QuickSort(int *e, int low, int high)
{
    if(low < high)
    {
        // Partition the array and get the pivot index#endif
        int pi = partition(e, low, high);

        // Recursively sort the elements before and after the pivot
        QuickSort(e, low, pi - 1);
        QuickSort(e, pi + 1, high);
    }
}


int partition(int *e, int low, int high)
{
    int pivot = e[high];   
    int i = low - 1; // Index of the smaller element

    // Rearrange elements based on the pivot
    for(int j = low; j <= high - 1; j++)
    {
        // If the current element is smaller than the pivot
        if(e[j] < pivot)
        {
            i++; // Increment the index of the smaller element
            swaps(&e[i], &e[j]); // Swap the current element with the element at index i
        }
    }

    // Place the pivot element in its correct position
    swaps(&e[i + 1], &e[high]);
    return i + 1;  // Return the partition index
}


#endif