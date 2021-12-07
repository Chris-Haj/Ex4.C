#include "GradesOperations.h"


void createReport(StudentList **list) {

    FILE *f = fopen("//home//chris//CLionProjects//Ex4.C//StudentsGrades.txt", "r+");
    int total = 0, only1 = 0, none = 0, max=0, min=100,maxID=0,minID=0;
    int id, grade1, grade2;
    double failed1 = 0, failed2 = 0;
    Student *cur=NULL;
    //a while loop to read from the file line by line and store the first, second and third integers we find into id, grade1, grade2 by the same order.
    while (!feof(f)) {

        fscanf(f, "%d %d %d", &id, &grade1, &grade2);
        //total is used to tell how many students are in the file, each time we take a new line (new student) total increments by 1.
        total++;
        //These if statements are used to keep track of the highest received mark , and the ID of who got the highest mark on the test between both dates.
        if(grade1>max&&grade1>grade2&&grade1>=0)
            max=grade1,maxID=id;
        else if(grade2>max&&grade2>grade1&&grade2>=0)
            max=grade2,maxID=id;
        //These if statements are used to keep track of the lowest received mark , and the ID of who got the lowest mark on the test between both dates.
        if(grade1<grade2&&grade1<min&&grade1>=0)
            min=grade1,minID=id;
        else if(grade2<min&&grade2<grade1&&grade2>=0)
            min=grade2,minID=id;
        //If a student didn't do either tests a or b, none increments by 1
        if (grade1 == -1 && grade2 == -1)
            none++;
        //If a student only did one test from a and b, only1 increments by 1
        else if ((grade1 == -1 && grade2 != -1) || (grade1 != -1 && grade2 == -1))
            only1++;
        //If a student got less than 60 on the first exam, failed1 increments by 1.
        if (grade1 < 60)
            failed1++;
        //If a student got less than 60 on the second exam, failed2 increments by 1.
        if (grade2 < 60)
            failed2++;
        cur= calloc(1, sizeof(Student));
        cur->id=id;
        cur->grade1=grade1;
        cur->grade2=grade2;
        addToList(*list,cur);
    }
    fclose(f);
    f = fopen("//home//chris//CLionProjects//Ex4.C//Report.txt", "w+");
    //failed1 and failed2 are divided by the total amount of students and multiplied by 100 to get the percentage of failures in the test
    failed1/=total,failed2/=total;
    failed1*=100,failed2*=100;
    fprintf(f, "Number of students in file: %d\n", total);
    fprintf(f, "Number of students who did only one test: %d\n", only1);
    fprintf(f, "Number of students who did neither tests: %d\n", none);
    fprintf(f,"Percentage of failure in test A: %%%.2f\n",failed1);
    fprintf(f,"Percentage of failure in test B: %%%.2f\n",failed2);
    fprintf(f,"Student with ID %d got the highest mark with: %d\n",maxID,max);
    fprintf(f,"Student with ID %d got the lowest mark with: %d\n",minID,min);
}