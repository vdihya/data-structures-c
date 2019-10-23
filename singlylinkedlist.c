#include<stdio.h>
#include<stdlib.h>
struct student
{
        char USN[20];
        char name [20];
        char branch [20];
        int sem;
        int pno[10];
        struct student *next;

};
typedef struct student* stu;
stu head = NULL;

stu create_node()
{
    stu newstudent = (stu)malloc(sizeof(struct student));
    printf("Input Student's Semester:");
    scanf("%d",&newstudent->sem);
    printf("Input Student's Name:");
    scanf("%s",newstudent->name);
    printf("Input Student's USN:");
    scanf("%s",newstudent->USN);
    printf("Input Student's Branch:");
    scanf("%s",newstudent->branch);
    printf("Input Student's Phone Number:");
    scanf("%s",newstudent->pno);

    newstudent->next= NULL;
    return (newstudent);
}

void create_list()
{
    stu newstudent;
     int value;
   while(1)
   {
    printf("Enter -999 to stop accepting values, enter any other to continue accepting values: ");
    scanf("%d",&value);
    if(value==-999)
    return;

        newstudent = create_node();
        if(head == NULL)
           {
              head = newstudent;
            }

        else //front insertion
        {
             newstudent->next = head;
             head = newstudent;
        }

    }

}


void display_nodes()
{   printf("\n\nUSN\t\tBranch\t\tName\t\tSemester\t\tPhone Number\n\n");
    stu temp;
    temp = head;
    while(temp!=NULL)
    {
         printf("%s\t\t%s\t\t%s\t\t%d\t\t\t%s\n\n",temp->USN,temp->branch,temp->name,temp->sem,temp->pno);
        temp = temp->next;
    }

}
void insert_beg()
{
    stu newstudent;
    newstudent = create_node();
    if(head == NULL)
        head = newstudent;
    else
    {

        newstudent->next = head;
        head = newstudent;
    }
    printf("A student has been successfully added to the beginning of the list.");
    return;
}
void insert_end()
{
    stu newstudent;
    stu temp = head;
    newstudent = create_node();
    if(head == NULL)
    {
    head = newstudent;
    }
    else
    {
        while(temp->next!= NULL)
            temp = temp->next;
        temp->next = newstudent;
    }

    printf("A student has been successfully added to the end of the list.");
    return;
}
void delete_beg()
{
     stu temp = head;
    if(head == NULL)
       printf("No students to delete.");
    else if(temp->next==NULL)
    {
    free(temp);
    head = NULL;
    }
    else
    {
        head = temp->next; // assign the address in temp->next to head so head will point to that address
        free(temp);
    }
     printf("A student has been successfully deleted from the beginning of the list.");
   return;
}
void delete_end()
{ stu temp = head;
 if(head == NULL)
    printf("No students to delete");
 else if(temp->next == NULL)
   {
     free(temp);
    head = NULL;
   }
  else
  {  stu temp1;
      while(temp->next!=NULL)
       {
       temp1 = temp; //to store previous node's value
        temp = temp->next;
       }
    free(temp);
    temp1->next = NULL;  }
  printf("A student has been successfully deleted from the end of the list.");
   return;

}
void insert_pos()
{   int pos; stu temp = head; int count = 0;
    printf("Enter position where you want to insert a new student: ");
    scanf("%d",&pos);
    int i=0;
    while(temp!=NULL){ temp = temp->next; count++;}
    if(pos > count || pos < 0) {printf("Invalid position, choose again: "); return;}
    if(head == NULL) {printf("No student to delete."); return;}
    temp = head;
    if(pos == 1) {insert_beg(); return;}
    while(temp->next!=NULL && i<pos-2)
    {temp=temp->next; i++;}
    stu newstudent = create_node();
    newstudent->next = temp->next;
    temp->next = newstudent;
    return;

}
void delete_pos()
{
    int pos; stu temp = head; int count = 0; int i = 0; stu prev;
    printf("Enter position where you want to delete a student: ");
    scanf("%d",&pos);
    while(temp!=NULL){ temp = temp->next; count++;}
    if(pos > count || pos < 0) {printf("Invalid position, choose again: "); return;}
    if(pos==1) {delete_beg(); return;}
    if(head == NULL) {printf("No student to delete."); return;}
    temp = head;
    while(temp->next!=NULL && i<pos-2)
    {
        temp=temp->next; i++;}
    temp->next = temp->next->next;
    return;

}
int main()
{
    int choice;
     for( ; ; )
   {

        printf("\n 1: Create a student linked list database,\n 2: Display student details,\n 3: Add a student to the beginning of the list,\n 4: Add a student to the end of the list,\n 5: Delete a student from the beginning of the list,\n 6: Delete a student from the end of the list,\n 7: Add a student at a specified position,\n 8: Delete a student from a specified position,\n 9: Exit\n");
        printf("Enter choice: ");
        scanf("%d",&choice);


       switch(choice)
    {
        case 1: create_list(); break;
        case 2: display_nodes(); break;
        case 3: insert_beg(); break;
        case 4: insert_end(); break;
        case 5: delete_beg(); break;
        case 6: delete_end(); break;
        case 7: insert_pos(); break;
        case 8: delete_pos(); break;
        case 9: exit(0);
        default: printf("Invalid Input, try again: ");
    }
    }
    return(0);
}
