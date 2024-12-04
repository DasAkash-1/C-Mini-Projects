#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 400

struct students {
    int id;
    char name[40];
    char number[10];
    char address[20];
    char mail[50];
} st[MAX];

int loc = 0;

void menu();
void add();
void find();
void load();
void save();
void update();
void delete();

void menu() {
    printf("\n*********************************************");
    printf("\n* Welcome to Computerized Student Directory *\n");
    printf("*********************************************\n");
    printf("1. Add Student\n");
    printf("2. Find Student by ID\n");
    printf("3. Update Student info\n");
    printf("4. Delete Student info\n");
    printf("5. Save to disk\n");
    printf("6. Load from disk\n");
    printf("7. Quit\n");
}

void add() {
    printf("Enter student name: ");
    fgets(st[loc].name, sizeof(st[loc].name), stdin);
    printf("Enter student ID: ");
    scanf("%d", &st[loc].id);
    printf("Enter number: ");
    fgets(st[loc].number, sizeof(st[loc].number), stdin);
    printf("Enter address: ");
    fgets(st[loc].address, sizeof(st[loc].address), stdin);
    printf("Enter e-mail: ");
    fgets(st[loc].mail, sizeof(st[loc].mail), stdin);

    loc++;
    printf("Student added!\n");
}

void find() {
    int find, found = 0;

    printf("Enter ID: ");
    scanf("%d", &find);
    getchar();

    for (int i = 0; i < loc; i++) {
        if (find == st[i].id) {
            printf("Student details:\n");
            printf("Name: %s\nNumber: %s\nAddress: %s\nMail: %s", st[i].name, st[i].number, st[i].address, st[i].mail);
            found = 1;
            break;
        }
    }
}

void update() {
    int ID;
    printf("Enter ID to update: ");
    scanf("%d", &ID);
    getchar();

    for (int i = 0; i < loc; i++) {
        if (ID == st[i].id) {
            printf("1. Name\n2. Number\n3. Address\n4. Mail\n");
            int choice_up;
            printf("Enter your choice: ");
            scanf("%d", &choice_up);
            getchar();

            switch (choice_up) {
                case 1:
                    printf("Enter NEW name: ");
                    fgets(st[i].name, sizeof(st[i].name), stdin);
                    break;
                case 2:
                    printf("Enter NEW number: ");
                    fgets(st[i].number, sizeof(st[i].number), stdin);
                    break;
                case 3:
                    printf("Enter NEW address: ");
                    fgets(st[i].address, sizeof(st[i].address), stdin);
                    break;
                case 4:
                    printf("Enter NEW mail: ");
                    fgets(st[i].mail, sizeof(st[i].mail), stdin);
                    break;
            }
            printf("Student info updated.\n");
            return;
        }
    }
}

void delete() {
    int del;
    printf("Enter student ID to delete: ");
    scanf("%d", &del);
    getchar();

    for (int i = 0; i < loc; i++) {
        if (del == st[i].id) {

            for (int j = i; j < loc - 1; j++) {
                st[j] = st[j + 1];
            }
            loc--;
            printf("Student deleted.\n");
            return;
        }
    }
    printf("Student not found!\n");
}

void save() {
    FILE *fp;
    fp = fopen("phone_windows.txt", "w");
    if (fp == NULL) {
        printf("Can't open file.\n");
        return;
    }


    for (int i = 0; i < loc; i++) {

        fprintf(fp, "%d\n%s\n%s\n%s\n%s\n", st[i].id, st[i].name, st[i].number, st[i].address, st[i].mail);
    }

    fclose(fp);
    printf("Saved to disk.\n");
}


void load(void) {
    FILE *fp;
    fp = fopen("phone.txt", "r");
    if (fp == NULL) {
        printf("Can't open file.\n");
        return;
    }

    loc = 0;
    while (fscanf(fp, "%d\n", &st[loc].id) == 1) {
     
        if (fgets(st[loc].name, sizeof(st[loc].name), fp) == NULL) 
        break;
        if (fgets(st[loc].number, sizeof(st[loc].number), fp) == NULL) 
        break;
        if (fgets(st[loc].address, sizeof(st[loc].address), fp) == NULL) 
        break;
        if (fgets(st[loc].mail, sizeof(st[loc].mail), fp) == NULL) 
        break;

        loc++;
    }

    fclose(fp);
    printf("File loaded.\n");
}


int main() {
    int choice;
    do {
        menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                add();
                break;
            case 2:
                find();
                break;
            case 3:
                update();
                break;
            case 4:
                delete();
                break;
            case 5:
                save();
                break;
            case 6:
                load();
                break;
            case 7:
                printf("Quitting\n");
                break;
            default:
                printf("Wrong choice\n");
        }
    } while (choice != 7);

    return 0;
}
