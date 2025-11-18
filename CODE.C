#include <stdio.h>
#include <string.h>

#define MAX 100

int roll[MAX];
char name[MAX][50];
float marks[MAX];
int n = 0;   // number of students

// ------------ LINEAR SEARCH ------------
int linearSearch(int key) {
    for (int i = 0; i < n; i++) {
        if (roll[i] == key)
            return i;
    }
    return -1;
}

// ------------ MERGE SORT ------------
void merge(int l, int mid, int r) {
    int i = l, j = mid + 1, k = 0;
    int tRoll[MAX];
    float tMarks[MAX];
    char tName[MAX][50];

    while (i <= mid && j <= r) {
        if (roll[i] < roll[j]) {
            tRoll[k] = roll[i];
            tMarks[k] = marks[i];
            strcpy(tName[k], name[i]);
            i++;
        } else {
            tRoll[k] = roll[j];
            tMarks[k] = marks[j];
            strcpy(tName[k], name[j]);
            j++;
        }
        k++;
    }

    while (i <= mid) {
        tRoll[k] = roll[i];
        tMarks[k] = marks[i];
        strcpy(tName[k], name[i]);
        i++; 
        k++;
    }

    while (j <= r) {
        tRoll[k] = roll[j];
        tMarks[k] = marks[j];
        strcpy(tName[k], name[j]);
        j++; 
        k++;
    }

    for (i = l, k = 0; i <= r; i++, k++) {
        roll[i] = tRoll[k];
        marks[i] = tMarks[k];
        strcpy(name[i], tName[k]);
    }
}

void mergeSort(int l, int r) {
    if (l < r) {
        int mid = (l + r) / 2;
        mergeSort(l, mid);
        mergeSort(mid + 1, r);
        merge(l, mid, r);
    }
}

// ------------ MAIN MENU ------------
int main() {
    int choice, key, index;

    while (1) {
        printf("\n--- Student Record Management (Arrays + Linear Search + Merge Sort) ---\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Search Student (Linear Search)\n");
        printf("4. Sort Students (Merge Sort)\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {

            case 1:
                printf("Enter Roll Number: ");
                scanf("%d", &roll[n]);

                printf("Enter Name: ");
                scanf("%s", name[n]);

                printf("Enter Marks: ");
                scanf("%f", &marks[n]);

                n++;
                printf("Student added successfully!\n");
                break;

            case 2:
                printf("\n--- Student Records ---\n");
                for (int i = 0; i < n; i++) {
                    printf("%d\t%s\t%.2f\n", roll[i], name[i], marks[i]);
                }
                break;

            case 3:
                printf("Enter Roll Number to Search: ");
                scanf("%d", &key);

                index = linearSearch(key);

                if (index != -1)
                    printf("Found: %d\t%s\t%.2f\n",
                           roll[index], name[index], marks[index]);
                else
                    printf("Record Not Found!\n");
                break;

            case 4:
                mergeSort(0, n - 1);
                printf("Records sorted successfully using Merge Sort!\n");
                break;

            case 5:
                return 0;

            default:
                printf("Invalid Choice!\n");
        }
    }
}
