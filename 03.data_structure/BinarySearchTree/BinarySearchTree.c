#include "BinarySearchTree.h"
#include "../util/error.h"
#include <malloc.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

Student *createStudent(char *birth, char name, int grade){
    Student *student = (Student*)malloc(sizeof(Student));
    strcpy(student->birth, birth);
    student->name = name;
    student->grade = grade;
    return student;
}

int main(int argc, char **argv){
    Student *s[20];
    FILE *fp = (argc > 1)? fopen(argv[1], "r") : fopen("student.txt", "r");

    if (fp == NULL)
        error("Couldn't open file");

    char line[1024];
    fgets(line, sizeof(line), fp);
    int i = 0;
    while (fgets(line, sizeof(line), fp) != NULL){
        char *birth = strtok(line, "\t");
        char *name = strtok(NULL, "\t");
        int grade = atoi(strtok(NULL, "\t"));
        printf("%s, %c, %d\n", birth, name[0], grade);
        s[i++] = createStudent(birth, name[0], grade);
    }

    fclose(fp);
}