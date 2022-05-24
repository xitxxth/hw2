#include "hw2.h"
int main(void)
{
    FILE* fp = fopen("input.txt", "r");
    if(!fp){
        printf("FILE OPEN FAILED!\n");
        exit(0);
    }//file opened
    while(1){//begin while
        int check;
        check=fscanf(fp, "%s", command);//getcommand
        if(check==EOF)    break;
        if(!strcmp(command, "INSERT")){//Insert
            fscanf(fp, "%d", &item);
            insert(item);
        }//end insert
        /*else if(!strcmp(command, "ASCEND")){//Ascend
            //fprintf
        }//end ascend
        else if(!strcmp(command, "DESCEND")){
            //fprintf
        }//end descend*/
    }//end while
    while(heap_size>0){
        printf("%d", max_heap[heap_size]);
    }
    fclose(fp);
    return 0;
}