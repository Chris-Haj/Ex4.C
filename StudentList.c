#include "StudentList.h"

StudentList *createList() {
// We create a StudentList using calloc, and intialize its head to null then return the list.
    StudentList *List = (StudentList *) calloc(1, sizeof(StudentList));
    List->head=NULL;
    return List;
}



void deleteList(StudentList *list) {

    //To free all the nodes in the list we use 2 pointers.
    //cur will be used to traverse the list while head will be used to free the block of memory we
    if(list==NULL||list->head==NULL)
        return;

    StudentNode *cur=list->head;
    StudentNode *delete=cur;
    while(cur!=NULL){
        cur=cur->next;
        free(delete);
        delete=NULL;
        delete=cur;
    }
    list->head=NULL;
}

void printStudentNode(StudentNode *const node) {
//We the print the StudentNode details by accessing all the data members of the node.
    if(node!=NULL)
        printf("Student of ID: %d, Grade1: %d, Grade2: %d\n",node->st->id,node->st->grade1,node->st->grade2);

}

void printStudentList(StudentList *const list) {

    //cur will point to the head of the linked list
    if(list==NULL||list->head==NULL){
        printf("List is empty!\n");
        return;
    }
    StudentNode *cur=list->head;
    //counter will be used how many students we traverse through.
    int counter=1;
    //while loop to traverse all the studentlist nodes and printing each student's details.
    while(cur!=NULL){
        printStudentNode(cur);
        cur=cur->next;
    }

}

void addToList(StudentList *list, Student *std) {

    //Cur points to head of list.
    if(list->head==NULL){
        list->head= calloc(1, sizeof(StudentNode));
        list->head->st=std;
        return;
    }
    StudentNode *cur=list->head;
    //while loop to find next free spot, once cur's next pointer points to NULL we exit
    while(cur->next!=NULL){
        cur=cur->next;
    }
    //we create a new student node at cur's next pointer
    cur->next = (StudentNode *) calloc(1, sizeof(StudentNode));
    //cur moves to next node.
    cur=cur->next;
    //cur's student pointer will point to received student address
    cur->st=std;

}
