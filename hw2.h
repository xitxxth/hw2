#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX_HEAP_SIZE 1000000

int heap[MAX_HEAP_SIZE];//global array-heap
void insert(int item);//insert item to the heap
int delete(void);//delete item from the heap
