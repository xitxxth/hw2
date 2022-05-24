#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAX_HEAP_SIZE 1000001
#define MAX_COMMAND_SIZE 8
int max_heap[MAX_HEAP_SIZE];//global array-heap
int min_heap[MAX_HEAP_SIZE];
char command[MAX_COMMAND_SIZE];
void insert(int item);//insert item to the heap
int delete(void);//delete item from the heap
int item;
int heap_size=0;

void insert(int item)
{//begin insert
    if(heap_size==MAX_HEAP_SIZE-1){
        printf("FULL\n");
        return;
    }//end if
    max_heap[++heap_size] = item;//initially input
    int i = heap_size;//for index
    while(i>1){//begin while
        if(item > max_heap[i/2]){//child > parent
            max_heap[i] = max_heap[i/2];
            i /= 2;
        }
    }//end while
    max_heap[i] = item;//insert done


}//end insert

/*int delete(void)
{

}*/