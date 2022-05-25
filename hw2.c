#include "hw2.h"//
int main(int argc, char* argv[])
{
    if(argc!=2){
        printf("The input file does not exist\n");
        exit(0);
    }
    int new_line_flag = 0;
    FILE* in = fopen(argv[1], "r");
    if(!in){
        printf("The input file does not exist\n");
        exit(0);
    }//file opened
    FILE* out = fopen("hw2_result.txt", "w");
    if(!out){
        printf("FILE DOESN'T EXIST!\n");
        exit(0);
    }//file make failed

    while(1){//begin while
        int check;
        if(fscanf(in, "%s", command)==EOF)   break;//getcommand
        if(!strcmp(command, "INSERT")){//Insert
            fscanf(in, "%d", &item);
            max_insert(item);
            min_insert(item);
        }//end insert

        else if(!strcmp(command, "ASCEND")){//Ascend
            for(int i=1; i<=min_heap_size; i++) copy_min_heap[i] = min_heap[i];
            int j=min_heap_size;
            if(new_line_flag)   fprintf(out, "\n");
            for(int i=1; i<=j; i++)  fprintf(out, "%d ", min_delete_heap());
            min_heap_size=j;
            for(int i=1; i<=min_heap_size; i++) min_heap[i] = copy_min_heap[i];
            new_line_flag=1;
        }//end ascend

        else if(!strcmp(command, "DESCEND")){
            for(int i=1; i<=max_heap_size; i++) copy_max_heap[i] = max_heap[i];
            int j=max_heap_size;
            if(new_line_flag)   fprintf(out, "\n");
            for(int i=1; i<=j; i++)  fprintf(out, "%d ", max_delete_heap());
            max_heap_size=j;
            for(int i=1; i<=max_heap_size; i++) max_heap[i] = copy_max_heap[i];
            new_line_flag=1;
        }//end descend
    }//end while
    if(fclose(in)){
        printf("FILE CLOSE ERROR\n");
        exit(0);
    }
    if(fclose(out)){
        printf("FILE CLOSE ERROR\n");
        exit(0);
    }
    printf("output written to hw2_result.txt.\n");
    printf("running time: %lf seconds\n", running_time);
    return 0;
}