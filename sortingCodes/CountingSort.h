#ifndef COUNTING_SORT_H
#define COUNTING_SORT_H


void CountingSort(int *e, int size)
{
    int output[size];
    int max = e[0];

    for(int i = 1; i < size; i++)
        if(e[i] > max)
            max = e[i];

    int countArray[max + 1];
    for(int i = 0; i <= max; i++)
        countArray[i] = 0;

    for(int i = 0; i < size; i++)
        countArray[e[i]]++;

    for(int i = 1; i <= max; i++)
        countArray[i] += countArray[i - 1];

    for(int i = size - 1; i >= 0; i--)
    {
        output[countArray[e[i]] - 1] = e[i];
        countArray[e[i]]--;
    }

    for(int i = 0; i < size; i++)
        e[i] = output[i];
}


#endif