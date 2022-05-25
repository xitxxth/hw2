#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#define MAX_HEAP_SIZE 1000001
#define MAX_COMMAND_SIZE 8
int max_heap[MAX_HEAP_SIZE];//global array-heap
int min_heap[MAX_HEAP_SIZE];
int copy_max_heap[MAX_HEAP_SIZE];
int copy_min_heap[MAX_HEAP_SIZE];
char command[MAX_COMMAND_SIZE];
void max_insert(int item);//insert item to the heap
void min_insert(int item);//insert item to min heap
int max_delete_heap(void);//delete item from the heap
int min_delete_heap(void);
int item;
int max_heap_size=0;
int min_heap_size=0;
double running_time=0;
clock_t start, end;

void max_insert(int item)
{//begin insert
    if(max_heap_size==MAX_HEAP_SIZE-1){
        printf("FULL\n");
        return;
    }//end if
    max_heap[++max_heap_size] = item;//initially input
    int i = max_heap_size;//for index
    while(i>1){//begin while
        if(item > max_heap[i/2]){//child > parent
            max_heap[i] = max_heap[i/2];
            i /= 2;
        }
        else    break;
    }//end while
    max_heap[i] = item;//insert done
}//end insert


int max_delete_heap(void)
{
    if(max_heap_size==0){
        printf("EMPTY\n");
        exit(0);
    }
    int parent=1, child=2;
    int item=max_heap[1], tmp=max_heap[max_heap_size];
    max_heap_size--;
    while(child<max_heap_size){
        if((child < max_heap_size) && (max_heap[child] < max_heap[child+1]))    child++;
        if(tmp >= max_heap[child])  break;;
        max_heap[parent] = max_heap[child];
        parent = child;
        child *= 2;
    }
    max_heap[parent] = tmp;
    return item;
}

void min_insert(int item)
{//start func
    if(min_heap_size==MAX_HEAP_SIZE-1){
        printf("FULL\n");
        return;
    }//end if
    min_heap[++min_heap_size] = item;//initially input
    int i = min_heap_size;//for index
    while(i>1){//begin while
        if(item < min_heap[i/2]){//child < parent
            min_heap[i] = min_heap[i/2];
            i /= 2;
        }
        else    break;
    }//end while
    min_heap[i] = item;//insert done
}//end func


int min_delete_heap(void)
{
    if(min_heap_size==0){
        printf("EMPTY\n");
        exit(0);
    }
    int parent=1, child=2;
    int item=min_heap[1], tmp=min_heap[min_heap_size];
    min_heap_size--;
    while(child < min_heap_size){
        if((child < min_heap_size) && (min_heap[child] > min_heap[child+1]))    child++;
        if(tmp <= min_heap[child])  break;;
        min_heap[parent] = min_heap[child];
        parent = child;
        child *= 2;
    }
    min_heap[parent] = tmp;
    return item;
}
