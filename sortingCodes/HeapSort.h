#ifndef HEAP_SORT_H
#define HEAP_SORT_H


void heapify(int *e, int size, int i);


void HeapSort(int *e, int size)
{
    // Build the max heap from the input array
    for(int i = size / 2 - 1; i >= 0; i--)
        heapify(e, size, i);

    // Extract elements from the heap one by one
    for(int i = size - 1; i > 0; i--)
    {
        // Move the current root (largest element) to the end
        swaps(&e[0], &e[i]);    
        
        // Call heapify on the reduced heap to maintain the heap property
        heapify(e, i, 0);
    }
}


void heapify(int e[], int size, int i)
{
    // Initialize the largest element as root
    int largest = i;

    // Calculate the indices of the left and right children
    int l = 2 * i + 1;
    int r = 2 * i + 2;

    // Check if the left child exists and is greater than the root
    if(l < size && e[l] > e[largest])
        largest = l;

    // Check if the right child exists and is greater than the largest so far
    if(r < size && e[r] > e[largest])
        largest = r;

    // If the largest is not the root, swap and recursively heapify the affected sub-tree
    if(largest != i)
    {
        swaps(&e[i], &e[largest]);
        heapify(e, size, largest);
    }
}

#endif