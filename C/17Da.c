#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
#include<conio.h>
#include <time.h>

#define MAX_NAME_LENGTH 20
#define MAX_DEPARTMENT_LENGTH 20
#define MAX_COURSE_LENGTH 20
#define MIN_YEAR 2000
#define MAX_YEAR 2022
#define numStudents 50

#pragma pack(1)
struct Student
{
    /*Structure Declaration*/
    int rollNumber;
    char name[MAX_NAME_LENGTH];
    char department[MAX_DEPARTMENT_LENGTH];
    char course[MAX_COURSE_LENGTH];
    int yearOfJoining;
};
#pragma pack()

int getkey();
void linkfloat();
void generateRandomStudents(struct Student students[]);
void rolldetails(struct Student students[],int i);
void yeardetails(struct Student students[],int y);

int main()
{
    system("cls");

    printf("\nI N I T I A T I N G . . . \n");

    struct Student students[numStudents];
    //int numStudents = sizeof(students) / sizeof(struct Student);

    generateRandomStudents(students);
    
    int repeat = 0;
    while(repeat != 27)
    {
        printf("\n\n");/*code*/
        
        int i; printf("Enter Roll No: "); scanf("%d",&i);
        rolldetails(students, i);
        
        int y; printf("Enter Year: "); scanf("%d",&y);
        yeardetails(students, y);
        
        fflush(stdin);
        printf("\n\nE N T E R  /  E S C . . . ");
        repeat = getkey(); printf("\n");
    }

    return 0;
}
int getkey()
{
    int ch;
    ch = getch();
    if(ch == 0)
    {
        ch = getch();
        return ch;
    }
    return ch;
}

void linkfloat()
{
    float a = 0, *b;
    b = &a;/*cause emulator to be linked*/
    a = *b;/*suppress the warning – variable not used*/
}

void generateRandomStudents(struct Student students[])
{
    srand(time(NULL)); // Seed the random number generator with current time

    for (int i = 0; i < numStudents; i++) {
        students[i].rollNumber = i + 1;

        // Generate random name
        for (int j = 0; j < MAX_NAME_LENGTH - 1; j++) {
            students[i].name[j] = 'A' + rand() % 26;
        }
        students[i].name[MAX_NAME_LENGTH - 1] = '\0'; // Null-terminate the string

        // Generate random department
        for (int j = 0; j < MAX_DEPARTMENT_LENGTH - 1; j++) {
            students[i].department[j] = 'A' + rand() % 26;
        }
        students[i].department[MAX_DEPARTMENT_LENGTH - 1] = '\0'; // Null-terminate the string

        // Generate random course
        for (int j = 0; j < MAX_COURSE_LENGTH - 1; j++) {
            students[i].course[j] = 'A' + rand() % 26;
        }
        students[i].course[MAX_COURSE_LENGTH - 1] = '\0'; // Null-terminate the string

        // Generate random year of joining
        students[i].yearOfJoining = rand() % (MAX_YEAR - MIN_YEAR + 1) + MIN_YEAR;
    }
}

void rolldetails(struct Student students[],int i)
{
    printf("Student %d\n", i);
    printf("Roll Number: %d\n", students[i-1].rollNumber);
    printf("Name: %s\n", students[i-1].name);
    printf("Department: %s\n", students[i-1].department);
    printf("Course: %s\n", students[i-1].course);
    printf("Year of Joining: %d\n", students[i-1].yearOfJoining);
}

void yeardetails(struct Student students[],int y)
{
    for (int i = 0; i < numStudents; i++)
    if(students[i].yearOfJoining == y)
    printf("%s\n", students[i].name);
}

/*->*/

/*for (int i = 0; i < numStudents; i++)
        {
            // Access individual struct variables
            printf("Student %d\n", i + 1);
            printf("Roll Number: %d\n", students[i].rollNumber);
            printf("Name: %s\n", students[i].name);
            printf("Department: %s\n", students[i].department);
            printf("Course: %s\n", students[i].course);
            printf("Year of Joining: %d\n", students[i].yearOfJoining);
            printf("---------------------------\n");
        }*/

/*printf("Student %d\n", i);
        printf("Roll Number: %d\n", students[i-1].rollNumber);
        printf("Name: %s\n", students[i-1].name);
        printf("Department: %s\n", students[i-1].department);
        printf("Course: %s\n", students[i-1].course);
        printf("Year of Joining: %d\n", students[i-1].yearOfJoining);
        printf("---------------------------\n");*/

/*for (int i = 0; i < numStudents; i++)
        if(students[i].yearOfJoining == j)
        printf("%s\n", students[i].name);*/