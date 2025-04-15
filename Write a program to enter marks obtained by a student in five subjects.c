//Write a program to enter marks obtained by a student in five subjects and then tell the student whether he/she has passed the specific subject or not. After that give the average of marks from all the subjects.//

#include<stdio.h>

int main() {
    int subject1, subject2, subject3, subject4, subject5;
    float average;

    printf("Enter the marks in Subject 1: ");
    scanf("%d", &subject1);
    if (subject1 < 0 || subject1 > 100) {
        printf("Invalid input, try again: ");
        scanf("%d", &subject1);
    }

    printf("Enter the marks in Subject 2: ");
    scanf("%d", &subject2);
    if (subject2 < 0 || subject2 > 100) {
        printf("Invalid input, try again: ");
        scanf("%d", &subject2);
    }

    printf("Enter the marks in Subject 3: ");
    scanf("%d", &subject3);
    if (subject3 < 0 || subject3 > 100) {
        printf("Invalid input, try again: ");
        scanf("%d", &subject3);
    }

    printf("Enter the marks in Subject 4: ");
    scanf("%d", &subject4);
    if (subject4 < 0 || subject4 > 100) {
        printf("Invalid input, try again: ");
        scanf("%d", &subject4);
    }

    printf("Enter the marks in Subject 5: ");
    scanf("%d", &subject5);
    if (subject5 < 0 || subject5 > 100) {
        printf("Invalid input, try again: ");
        scanf("%d", &subject5);
    }

    if (subject1 >= 40)
        printf("You passed subject 1\n");
    else
        printf("You failed subject 1\n");

    if (subject2 >= 40)
        printf("You passed subject 2\n");
    else
        printf("You failed subject 2\n");

    if (subject3 >= 40)
        printf("You passed subject 3\n");
    else
        printf("You failed subject 3\n");

    if (subject4 >= 40)
        printf("You passed subject 4\n");
    else
        printf("You failed subject 4\n");

    if (subject5 >= 40)
        printf("You passed subject 5\n");
    else
        printf("You failed subject 5\n");

    average = (subject1 + subject2 + subject3 + subject4 + subject5) / 5.0;
    printf("Average marks = %.2f\n", average);

    return 0;
}


