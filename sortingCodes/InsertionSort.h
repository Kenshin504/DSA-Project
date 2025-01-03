#ifndef INSERTION_SORT_H
#define INSERTION_SORT_H


void InsertionSort(int *e, int size)
{
        for(int i = 1; i < size; i++)
    {
        int key = e[i];
        int j = i - 1;

        while(j >= 0 && e[j] > key)
        {
            e[j + 1] = e[j];
            j -= 1;
        }
         
        e[j + 1] = key;

    }
}

#endif