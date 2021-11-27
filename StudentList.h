#ifndef STUDENT_LIST_H
#define STUDENT_LIST_H
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
	int id;
	int grade1, grade2;
}Student;

typedef struct {
   Student* st;
   struct StudentNode* next;
}StudentNode;

typedef struct {
  StudentNode *head;
}StudentList;


StudentList* createList();
void deleteList(StudentList*);
void printStudentNode(StudentNode* const);
void printStudentList(StudentList* const);
void addToList(StudentList*, Student*);
#endif