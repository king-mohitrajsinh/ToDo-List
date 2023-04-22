#include <stdio.h>
#include <stdlib.h>

typedef struct ToDo todo;

struct ToDo {
    char data[100];
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

int main() {
    int choice;
    welcomeUser();
    while (1) {
        system("color 8F");
        system("cls");
        printf("\n1.See Your ToDo List");
        printf("\n2.Create Your ToDos");
        printf("\n3.Delete Your ToDos");
        printf("\n4.Exit");
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
                exit(0);
        }
    }
}

void seeToDo() {
    system("cls");
    todo *temp = start;
    int count = 0;
    if (temp == NULL) { 
        printf("\nYour ToDo list is empty.\n\n");
    } else {
        printf("\nYour ToDo list:\n\n");
        while (temp != NULL) {
            printf("%d) %s\n", temp->count, temp->data);
            count++;
            temp = temp->link;
        } 
        printf("\nTotal %d items.\n\n", count);
    }
    system("pause");
}


void createToDo(){
    char k;
    todo *t,*temp;
    system("cls");
    while(1){
        printf("\nWant to add?y/n");
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
                t=t->link;
            }
        }
    }
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

