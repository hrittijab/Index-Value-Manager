
#include "ex8q1.h"

float *indices;
int *values;
int size;

void insertion_sort(float *indices, int *values, int array_size)
{
    for (int i = 1; i < array_size; i++)
    {
        float key_index = indices[i];
        int key_value = values[i];
        int j = i - 1;

        while (j >= 0 && indices[j] > key_index)
        {
            indices[j + 1] = indices[j];
            values[j + 1] = values[j];
            j--;
        }

        indices[j + 1] = key_index;
        values[j + 1] = key_value;
    }
}

void print_array(int size, int* values)   // print the array
{
    printf("[");
    for (int i=0;i< (size-1); i++)
    {
        printf("%d, ", values[i]);

    }
    if(size > 0){
    printf("%d",values[size-1]);
}
    printf("]\n");
}

int main()
{
    int size=0;
    int* values;
    float* indices;
    indices = (float *)malloc(size * sizeof(float));
    values = (int *)malloc(size * sizeof(int));
    int is_print;
    float index;
    int value;

    while (!feof(stdin))
    {
        read_line(&is_print, &index, &value);
        if (is_print) print_array(size, values);
        else
        {
            int index_present =0;
            for (int i=0; i<size; i++)
            {
                if(indices[i] == index)
                {
                    values[i] = value;
                    index_present = 1;
                }

            }

            if(index_present == 0)
            {
                values=(int*)realloc(values,(size+1)*sizeof(int));
                indices=(float*)realloc(indices,(size+1)*sizeof(float));
                values[size]=value;
                indices[size]=index;
                size++;
                insertion_sort(indices, values,size);
            }

        }

    }

    free(indices);
    free(values);
    return 0;
}
