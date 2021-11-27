#include "StudentList.h"

StudentList *createList() {

    return NULL;
}

void deleteList(StudentList *list) {

}

void printStudentNode(StudentNode *const node) {

}

void printStudentList(StudentList *const list) {

    FILE *f = fopen("C:\\Users\\chris\\CLionProjects\\Ex4\\StudentsGrades.txt", "r+");
    if (f == NULL) {
        printf("No file found.\n");
        return;
    }
    int id, grade1, grade2;
    while (!feof(f)) {
        fscanf(f, "%d %d %d", &id, &grade1, &grade2);
        printf("ID: %d, grade1: %d, grade2, %d\n", id, grade1, grade2);
    }
    fclose(f);
}

void addToList(StudentList *list, Student *std) {

    FILE *f = fopen("C:\\Users\\chris\\CLionProjects\\Ex4\\StudentsGrades.txt", "r+");
    int total = 0, only1 = 0, none = 0;
    int id, grade1, grade2;
    double passed1=0,passed2=0;
    while (!feof(f)) {
        fscanf(f, "%d %d %d", &id, &grade1, &grade2);
        total++;
        if(grade1==-1&&grade2==-1)
            none++;
        else if((grade1==-1&&grade2!=-1) ||(grade1!=-1&&grade2==-1))
            only1++;
        if(grade1>=60)
            passed1++;
        if(grade2>=60)
            passed2++;
    }
    fclose(f);

    f = fopen("C:\\Users\\chris\\CLionProjects\\Ex4\\Report.txt","w+");


    fprintf(f,"Number of students in file: %d\n",total);
    fprintf(f,"Number of students who did only one test: %d\n",only1);
    fprintf(f,"Number of students who did neither tests: %d",none);



}
