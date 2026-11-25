/*name RUDRA Yadav
batch 20 
sap id 590037426
*/

#include <stdio.h>

struct Student {
    int rollNo;
    char name[50];
    float marks[5];
    float total;
    float percentage;
    char grade;
    int pass;
};

struct Student students[50];
int studentCount = 0;


/* Function to Add Student */
void addStudent() {
    int i;

    if (studentCount >= 50) {
        printf("\nMaximum student limit reached.\n");
        return;
    }

    printf("\nEnter Roll Number: ");
    scanf("%d", &students[studentCount].rollNo);

    printf("Enter Student Name: ");
    scanf(" %49[^\n]", students[studentCount].name);

    students[studentCount].total = 0;
    students[studentCount].pass = 1;

    printf("\nEnter marks out of 100:\n");

    for (i = 0; i < 5; i++) {

        printf("Subject %d: ", i + 1);
        scanf("%f", &students[studentCount].marks[i]);

        students[studentCount].total =
            students[studentCount].total +
            students[studentCount].marks[i];

        if (students[studentCount].marks[i] < 40) {
            students[studentCount].pass = 0;
        }
    }

    students[studentCount].percentage =
        students[studentCount].total / 5;

    if (students[studentCount].pass == 0) {
        students[studentCount].grade = 'F';
    }
    else if (students[studentCount].percentage >= 90) {
        students[studentCount].grade = 'A';
    }
    else if (students[studentCount].percentage >= 80) {
        students[studentCount].grade = 'B';
    }
    else if (students[studentCount].percentage >= 70) {
        students[studentCount].grade = 'C';
    }
    else if (students[studentCount].percentage >= 60) {
        students[studentCount].grade = 'D';
    }
    else {
        students[studentCount].grade = 'E';
    }

    studentCount++;

    printf("\nStudent result added successfully!\n");
}


/* Function to Display All Results */
void displayResults() {
    int i, j;

    if (studentCount == 0) {
        printf("\nNo student records available.\n");
        return;
    }

    for (i = 0; i < studentCount; i++) {

        printf("\n----------------------------\n");

        printf("Roll Number : %d\n", students[i].rollNo);
        printf("Name        : %s\n", students[i].name);

        printf("Marks       : ");

        for (j = 0; j < 5; j++) {
            printf("%.1f ", students[i].marks[j]);
        }

        printf("\nTotal       : %.1f / 500\n",
               students[i].total);

        printf("Percentage  : %.2f%%\n",
               students[i].percentage);

        printf("Grade       : %c\n",
               students[i].grade);

        if (students[i].pass == 1) {
            printf("Result      : PASS\n");
        }
        else {
            printf("Result      : FAIL\n");
        }
    }
}


/* Function to Search Student */
void searchStudent() {
    int roll, i;
    int found = 0;

    printf("\nEnter Roll Number to search: ");
    scanf("%d", &roll);

    for (i = 0; i < studentCount; i++) {

        if (students[i].rollNo == roll) {

            printf("\nStudent Found!\n");

            printf("Name       : %s\n",
                   students[i].name);

            printf("Total      : %.1f / 500\n",
                   students[i].total);

            printf("Percentage : %.2f%%\n",
                   students[i].percentage);

            printf("Grade      : %c\n",
                   students[i].grade);

            if (students[i].pass == 1) {
                printf("Result     : PASS\n");
            }
            else {
                printf("Result     : FAIL\n");
            }

            found = 1;
            break;
        }
    }

    if (found == 0) {
        printf("\nStudent not found.\n");
    }
}


/* Function to Show Class Topper */
void showTopper() {
    int i;
    int topper = 0;

    if (studentCount == 0) {
        printf("\nNo student records available.\n");
        return;
    }

    for (i = 1; i < studentCount; i++) {

        if (students[i].percentage >
            students[topper].percentage) {

            topper = i;
        }
    }

    printf("\n----- CLASS TOPPER -----\n");

    printf("Name       : %s\n",
           students[topper].name);

    printf("Roll Number: %d\n",
           students[topper].rollNo);

    printf("Percentage : %.2f%%\n",
           students[topper].percentage);

    printf("Grade      : %c\n",
           students[topper].grade);
}


/* Function to Calculate Class Average */
void classAverage() {
    int i;
    float sum = 0;
    float average;

    if (studentCount == 0) {
        printf("\nNo student records available.\n");
        return;
    }

    for (i = 0; i < studentCount; i++) {
        sum = sum + students[i].percentage;
    }

    average = sum / studentCount;

    printf("\nClass Average Percentage: %.2f%%\n",
           average);
}


/* Academic Advisor Function */
void academicAdvisor() {

    int roll, i, j;
    int found = 0;
    int weakestSubject;
    float lowestMarks;

    if (studentCount == 0) {
        printf("\nNo student records available.\n");
        return;
    }

    printf("\nEnter Roll Number for Academic Advice: ");
    scanf("%d", &roll);

    for (i = 0; i < studentCount; i++) {

        if (students[i].rollNo == roll) {

            found = 1;

            printf("\n============================");
            printf("\n      ACADEMIC ADVISOR");
            printf("\n============================\n");

            printf("Name       : %s\n",
                   students[i].name);

            printf("Percentage : %.2f%%\n",
                   students[i].percentage);

            printf("Grade      : %c\n",
                   students[i].grade);

            /* Find Weakest Subject */

            weakestSubject = 0;
            lowestMarks = students[i].marks[0];

            for (j = 1; j < 5; j++) {

                if (students[i].marks[j] < lowestMarks) {

                    lowestMarks =
                        students[i].marks[j];

                    weakestSubject = j;
                }
            }

            printf("Weakest Subject : Subject %d\n",
                   weakestSubject + 1);

            printf("Marks in Weakest Subject : %.1f\n",
                   lowestMarks);

            printf("\nAcademic Advice:\n");

            if (students[i].pass == 0) {

                printf("Focus on your failed subjects.\n");
                printf("Revise basic concepts and practice regularly.\n");
            }

            else if (students[i].percentage >= 90) {

                printf("Excellent performance!\n");
                printf("Keep maintaining your consistency.\n");
            }

            else if (students[i].percentage >= 80) {

                printf("Very good performance.\n");
                printf("Focus more on your weaker subject to reach 90%%.\n");
            }

            else if (students[i].percentage >= 70) {

                printf("Good performance.\n");
                printf("Regular practice can improve your score.\n");
            }

            else if (students[i].percentage >= 60) {

                printf("Satisfactory performance.\n");
                printf("Give extra time to your weaker subjects.\n");
            }

            else {

                printf("You need improvement.\n");
                printf("Practice daily and strengthen your basic concepts.\n");
            }

            break;
        }
    }

    if (found == 0) {
        printf("\nStudent not found.\n");
    }
}


/* Main Function */
int main() {

    int choice;

    do {

        printf("\n====================================");
        printf("\n  STUDENT RESULT & GRADE ANALYZER");
        printf("\n====================================");

        printf("\n1. Add Student Result");
        printf("\n2. Display All Results");
        printf("\n3. Search Student");
        printf("\n4. Show Class Topper");
        printf("\n5. Show Class Average");
        printf("\n6. Academic Advisor");
        printf("\n7. Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                addStudent();
                break;

            case 2:
                displayResults();
                break;

            case 3:
                searchStudent();
                break;

            case 4:
                showTopper();
                break;

            case 5:
                classAverage();
                break;

            case 6:
                academicAdvisor();
                break;

            case 7:
                printf("\nThank you for using the program!\n");
                break;

            default:
                printf("\nInvalid choice. Please try again.\n");
        }

    } while (choice != 7);

    return 0;
}
	

	
