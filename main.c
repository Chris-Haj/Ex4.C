#include <stdio.h>
#include "StudentList.h"
#include "GradesOperations.h"


int main() {

    StudentList *List = createList();
    StudentNode *node=List->head;
    while(node!=NULL){
        printStudentNode(node);
        node=node->next;
    }
    printf("\n");
    deleteList(List);
    node=List->head;
    if(List!=NULL)
        printf("not empty!\n");
int counter=0;
    while(node!=NULL){
        printStudentNode(node);
        node=node->next;
        counter++;
        if(counter==20)
            break;
    }
    return 0;
}
