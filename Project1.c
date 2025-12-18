// Student Management System
#include<stdlib.h>
#include<stdio.h>
#include<string.h>

struct student {
                    int roll;
                    char name[50];
                    float marks;
                    struct student *next;
};
 struct student *head=NULL;
 // Function Prototypes
 void addStudent();
 void displayStudent();
 void searchStudent();
 void deletStudent();
 // Add Student
 void addStudent(){
                    struct student *newNode, *temp;
    newNode = (struct student *)malloc(sizeof(struct student));

    printf("Enter Roll: ");
    scanf("%d", &newNode->roll);

    printf("Enter Name: ");
    scanf("%s", newNode->name);

    printf("Enter Marks: ");
    scanf("%f", &newNode->marks);

    newNode->next = NULL;

    if (head == NULL) {
        head = newNode;
    } else {
        temp = head;
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }

    printf("Student added successfully!\n");
 }
 //Display Student
 void displaystudent(){
                    struct student *temp=head;
                    if(head==NULL){
                                        printf("No student Found!\n");
                                        return ;
                    }
                    printf("Student List:\n");
                    while(temp!=NULL){
                                        printf("Roll:%d\n",temp->roll);

                                        printf("Name:%s\n",temp->name);

                                        printf("Marks:%2.f\n",temp->marks);
                                        temp=temp->next;
                    }
 }

 //Search Student
 void searchStudent(){
                    struct student *temp=head;
                    int roll,found=0;
                    printf("Enter Roll Number to Search:");
                    scanf("%d",&roll);
                    while(temp!=NULL){
                                        if(temp->roll==roll){
                                                            printf("Student Found!\n");
                                                            printf("Roll: %d\n",temp->roll);
                                                            printf("Name: %s\n",temp->name);
                                                            printf("Marks: %2f\n",temp->marks);
                                                            found=1;
                                                            break;
                                        }
                                        temp=temp->next;
                    }
                    if(!found)
                    printf("Student Not found!\n");
 }
 // Delete Student
 void deletStudent(){
                    int roll;
                    struct student *temp=head;
                    struct student *prevNode=NULL;
                    if(head==NULL){
                                        printf("List is empty!\n");
                                        return;
                    }
                    printf("Enter a roll to Delet:");
                    scanf("%d",&roll);

                    if(head->roll==roll){
                                        temp=head;
                                        head=head->next;
                                        free(temp);
                                        printf("Delete Successfully!");
                                        return ;
                    }
                    while(temp!=NULL && temp->roll!=roll){
                                        prevNode=temp;
                                        temp=temp->next;

                    }
                    if(temp==NULL){
                                        printf("No student found!\n");
                    }else{
                                        prevNode->next=temp->next;
                                        free(temp);
                                        printf("Student Delete Sucessfully!\n");
                    }
 }
 int main(){
                    int choice;


                    while(1){
                                        printf("\n====== Student Management System=======\n");

                                        printf("1. Add Student \n");
                                        printf("2. Display Student\n");
                                        printf("3. Search Student\n");
                                        printf("4. Delete Student\n");
                                        printf("5. Exit\n");
                                        printf("Enter Your Choice: ");
                                        scanf("%d",&choice);
   switch(choice){
                                                   case 1:
                addStudent();
                break;
            case 2:
                displaystudent();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                deletStudent();
                break;
            case 5:
                printf("Exiting program...\n");
                exit(0);
            default:
                printf("Invalid choice! Try again.\n");         
                                        }


                    }
                    return 0;
 }
 