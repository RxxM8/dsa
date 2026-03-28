#include <stdio.h>
#include <string.h>

#define MAX 100

struct Document{
    char name[50];
    int pages;
};

struct Document queue[MAX];
int front=-1;
int rear=-1;

void add(){
    if(rear==MAX-1){
        printf("Printer Queue Full!\n");
    }
    else{
    struct Document doc;
    printf("Enter file name:");
    scanf("%s",&doc.name);
    printf("Enter pages:");
    scanf("%d",&doc.pages);

    if (front==-1){
        front = 0;
    }
    rear++;
    queue[rear]=doc;
    printf("'%s' added to queue.\n", doc.name);

}
}

void print() {
    if (front==-1||front>rear) {
        printf("No documents in queue!\n");
      
    }
    else{
    printf("Printing: '%s' (%d pages)\n", queue[front].name,queue[front].pages);
    front++;
    }
}

void displayPending(){
    if (front==-1||front>rear) {
        printf("No pending documents.\n");
    }
    else{
    printf("\nPending Documents:\n");
    for (int i=front;i<=rear;i++) {
        printf("%s - %d pages\n",queue[i].name, queue[i].pages);
    }
}
}

int main() {
    int choice;

    while(1){
        printf("\n   Printer Queue   \n");
        printf("1) Add Document\n");
        printf("2) Print Document\n");
        printf("3) Display Pending\n");
        printf("4) Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        if(choice==1){
             add();
        }

        else if(choice==2){
             print();
        }

        else if(choice==3) {
            displayPending();
        }

        else if(choice==4) {
            break;
        }

        else {
            printf("Invalid choice!\n");
        }

    }

    return 0;
}