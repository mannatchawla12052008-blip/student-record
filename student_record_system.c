#include <stdio.h>
#include <string.h>

struct Student {
    int roll;
    char name[30];
    float marks;
};

int main() {
    struct Student s[50];
    int n = 0, choice, i, j, roll, found;

    do {
        printf("\n--- STUDENT RECORD SYSTEM ---\n");
        printf("1. Add\n2. Display\n3. Search\n4. Update\n5. Delete\n0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            if (n == 50) {
                printf("Record full!\n");
                break;
            }
            printf("Roll no: ");
            scanf("%d", &s[n].roll);
            printf("Name (no spaces): ");
            scanf("%s", s[n].name);
            printf("Marks: ");
            scanf("%f", &s[n].marks);
            n++;
            printf("Student added.\n");
            break;

        case 2:
            if (n == 0)
                printf("No records.\n");
            for (i = 0; i < n; i++)
                printf("%d  %s  %.2f\n", s[i].roll, s[i].name, s[i].marks);
            break;

        case 3:
            printf("Enter roll no: ");
            scanf("%d", &roll);
            found = 0;
            for (i = 0; i < n; i++)
                if (s[i].roll == roll) {
                    printf("%d  %s  %.2f\n", s[i].roll, s[i].name, s[i].marks);
                    found = 1;
                }
            if (!found)
                printf("Not found.\n");
            break;

        case 4:
            printf("Enter roll no to update: ");
            scanf("%d", &roll);
            found = 0;
            for (i = 0; i < n; i++)
                if (s[i].roll == roll) {
                    printf("New name: ");
                    scanf("%s", s[i].name);
                    printf("New marks: ");
                    scanf("%f", &s[i].marks);
                    found = 1;
                }
            if (!found)
                printf("Not found.\n");
            break;

        case 5:
            printf("Enter roll no to delete: ");
            scanf("%d", &roll);
            found = 0;
            for (i = 0; i < n; i++)
                if (s[i].roll == roll) {
                    for (j = i; j < n - 1; j++)
                        s[j] = s[j + 1];
                    n--;
                    found = 1;
                    printf("Deleted.\n");
                    break;
                }
            if (!found)
                printf("Not found.\n");
            break;

        case 0:
            printf("Bye!\n");
            break;

        default:
            printf("Invalid choice.\n");
        }
    } while (choice != 0);

    return 0;
}