#include <stdio.h>
#include <stdlib.h>

typedef struct ToDo todo;

struct ToDo {
    char data[1800];
    todo *link;
    int count;
};

void welcomeUser() {
    system("color 3F");
    printf("\n\n\n\n\n");
    printf("\t------------------------------------------------------------------------------------------------------\n\n");
    printf("\t#################################### YOUR TODO LIST APP ##############################################\n\n");
    printf("\t------------------------------------------------------------------------------------------------------");
    printf("\n\n\n\t\t*******************************WELCOME*******************************\n\n\n\n\n\n\n\n\n\t");
    system("pause");
}

todo *start = NULL;

void welcomeUser();
void seeToDo();
void createToDo();
void delToDo();
void fixcount();
void updateToDo();
void saveToFile();
void readFromFile();

int main() {
    int choice;
    welcomeUser();
    while (1) {
        system("color 8F");
        system("cls");
        printf("\n1.See Your ToDo List.");
        printf("\n2.Create Your ToDos.");
        printf("\n3.Delete Your ToDos.");
        printf("\n4.update your ToDos.");
        printf("\n5.save your todos in File.");
        printf("\n6.read your Todos from file.");
        printf("\n7.Exit");
        printf("\n\nEnter your choice..");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                seeToDo();
                break;
            case 2:
                createToDo();
                break;
            case 3:
                delToDo();
                break;
            case 4:
            	updateToDo();
            	break;
            case 5:
            	saveToFile();
            	break;
            case 6:
		readFromFile();
		break;
            case 7:
                exit(0);
            default:
printf("\nInvalid choice! Please try again.\n");
		}
	}
 }
void seeToDo() {
    system("cls");
    todo *temp = start;
    int count = 0;

    if (temp == NULL) {
        printf("Your todo list is empty.\n");
        system("pause");
        return;
    }

    printf("ToDo List:\n");
    while (temp != NULL) {
        count++;
        printf("%d. %s\n", count, temp->data);
        temp = temp->link;
    }
    printf("\n");
    system("pause");
}
void createToDo(){
    char k;
    todo *t,*temp;
    system("cls");
    FILE *fp;
    fp = fopen("todos.txt", "a"); // open file in append mode
    while(1){
        printf("\nWant to add? y/n ");
        fflush(stdin);
        scanf("%c",&k);
        if(k=='n')
            break;
        else {
            if(start==NULL){
                t=(todo *)calloc(1,sizeof(todo));
                start=t;
                printf("\nADD it..\n");
                fflush(stdin);
                gets(t->data);
                t->count=1;
                start->link=NULL;
            }
            else{
                temp=(todo *)calloc(1,sizeof(todo));
                printf("\nADD it..\n");
                fflush(stdin);
                gets(temp->data);
                temp->link=NULL;
                t->link=temp;
                t=t->link; // Fix: assign the new todo item to t instead of temp
            }
            // write data to file
            fprintf(fp, "%s\n", t->data); // Fix: write the new todo item to file using t instead of temp
        }
    }
    fclose(fp); // close the file
}
void delToDo(){
  system("cls");
  int d;
  todo *temp1,*temp;
  printf("\nEnter the no of the todo you want to remove\n");
  scanf("%d",&d);
  temp1=start;
  temp=start->link;
  while(1){
  if(temp1->count==d){
    start=start->link;
    free(temp1);
    fixcount();
    break;
  }
    if(temp->count==d){
        temp1->link=temp->link;
        free(temp);
        fixcount();
        break;
    }
    else{
        temp1=temp;
        temp=temp->link;
    }
}
system("pause");
}

void updateToDo() {
	system("cls");
    int n, flag = 0;
    todo *temp = start;

    if (temp == NULL) {
        printf("Error! Your ToDo list is empty.\n");
        system("pause");
        return;
    }

    printf("Enter the number of ToDo list to update: ");
    scanf("%d", &n);

    while (temp != NULL) {
        if (temp->count == n) {
            flag = 1;
            printf("Enter updated ToDo task: ");
            scanf(" %[^\n]", temp->data);
            printf("ToDo list updated successfully.\n");

            // write changes to file
            FILE *fp;
            fp = fopen("todos.txt", "w");
            todo *t = start;
            while (t != NULL) {
                fprintf(fp, "%s\n", t->data);
                t = t->link;
            }
            fclose(fp);

            break;
        }
        temp = temp->link;
    }

    if (flag == 0) {
        printf("Error! ToDo list with count %d does not exist.\n", n);
    }
system("pause");
}

void saveToFile(){
    FILE *fp;
    todo *temp = start;
    fp = fopen("todos.txt", "w"); // open file in write mode
    if(fp == NULL) {
        printf("Error opening file.\n");
        return;
    }
    while(temp != NULL) {
        fprintf(fp, "%s\n", temp->data);
        temp = temp->link;
    }
    fclose(fp);
    printf("Your ToDo list has been saved to file successfully.\n");
    system("pause");
}

void readFromFile() {
	system("cls");
    FILE *fp;
    char line[1800];
    int count = 0;
    fp = fopen("todos.txt", "r");

    if (fp == NULL) {
        printf("Failed to open the file.\n");
        return;
    }

    printf("Your ToDo List from file:\n");

    while (fgets(line, sizeof(line), fp) != NULL) {
        printf("%s", line);
        count++;
    }

    printf("\nTotal %d items.\n\n", count);
    fclose(fp);
    system("pause");
}

void fixcount(){
  todo * temp;
  int i=1;
  temp=start;
  while(temp!=NULL){
    temp->count=i;
    i++;
    temp=temp->link;
  }

}

