#ifndef MERGE_SORT_H
#define MERGE_SORT_H


void merge(int *e, int left, int mid, int right);


void MergeSort(int *e, int left, int right)
{
    if(left < right)
    {
        // Find the middle point of the current sub-array
        int mid = left + (right - left) / 2;

        // Recursively sort the left and right halves
        MergeSort(e, left, mid);
        MergeSort(e, mid + 1, right);

        // Merge the sorted halves
        merge(e, left, mid, right);
    }
}


void merge(int *e, int left, int mid, int right)
{
    int i, j, k;
    // Sizes of the two sub-arrays to merge
    int n1 = mid - left + 1;
    int n2 = right - mid;

    // Temporary arrays to hold the two halves
    int L[n1], R[n2];

    // Copy data to the temporary arrays L[] and R[]
    for(i = 0; i < n1; i++)
        L[i] = e[left + i];
    for(j = 0; j < n2; j++)
        R[j] = e[mid + 1 + j];

    // Initial indices of the sub-arrays and merged array
    i = 0; 
    j = 0;
    k = left;

    // Merge the temporary arrays back into the original array
    while(i < n1 && j < n2)
    {
        if(L[i] <= R[j])
        {
            e[k] = L[i];
            i++;
        }
        else 
        {
            e[k] = R[j];
            j++;
        }
        k++;
    }

    // Copy any remaining elements of L[]
    while(i < n1)
    {
        e[k] = L[i];
        i++;
        k++;
    }

    // Copy any remaining elements of R[]
    while(j < n2)
    {
        e[k] = R[j];
        j++;
        k++;
    }
}


#endif