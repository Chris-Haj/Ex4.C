#include <stdio.h>
#include "StudentList.h"
#include "GradesOperations.h"


int main() {

    StudentList *List = createList();
    StudentNode *head  = calloc(1, sizeof(StudentNode));
    List->head=head;
    head->st = (Student *) calloc(1, sizeof(Student));
    FILE *f = fopen("C:\\Users\\chris\\CLionProjects\\Ex4\\StudentsGrades.txt", "r+");
    fscanf(f,"%d %d %d",&(head->st->id),&(head->st->grade1),&(head->st->grade2));
    printf("%d %d %d",head->st->id,head->st->grade1,head->st->grade2);

    return 0;
}
