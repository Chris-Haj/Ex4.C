#include <stdio.h>
#include "StudentList.h"
#include "GradesOperations.h"

void change(int *x);

int main() {

    StudentList *List = createList();
    createReport(&List);
    printStudentList(List);
    free(List);
    List=NULL;
    deleteList(List);
    printStudentList(List);

    return 0;
}

void change(int *x){
    *x+=10;
}

