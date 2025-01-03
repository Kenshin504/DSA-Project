#ifndef SELECTION_SORT_H
#define SELECTION_SORT_H


void SelectionSort(int *e, int size)
{
    for(int i = 0; i < size - 1; i++)
    {
        int min = i; 

        for(int j = i + 1; j < size; j++)
        {
            if(e[j] < e[min])
                min = j;
        }
        swaps(&e[i], &e[min]);
    }
}


#endif