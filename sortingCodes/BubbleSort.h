#ifndef BUBBLE_SORT_H
#define BUBBLE_SORT_H

void BubbleSort(int *e, int size)
{
    for(int i = 0; i < size - 1; i++)
    {
        for(int j = 0; j < size - 1 - i; j++)
        {
            if(e[j] > e[j + 1])
                swaps(&e[j], &e[j + 1]);
        }
    }
}

#endif