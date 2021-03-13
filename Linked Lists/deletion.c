#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct NODE
{
    int roll_number;
    char name[100];
    struct NODE *next;
};

typedef struct NODE node;

void linkedlistTraversal(node *ptr)
{
    while(ptr != NULL)
    {
        printf("\nRoll number: %d", ptr->roll_number);
        printf("\tName: %s", ptr->name);
        ptr = ptr->next;
    }
}

node * deleteAtBeginning(node *start)
{   
    node *p = start;
    start = start->next;
    free(p);
    return start;
}

void deleteAtEnd(node *start)
{   
   node *p = start, *q = start->next;
   while(q->next != NULL)
    {
        p = p->next;
        q = q->next;
    }
    p->next = NULL;
    free(q);
}
void deleteAtIndex(node *start,int n) //index starts from 0
{
    node *p = start, *q = start->next;
    for(int i = 0; i<n-1 ; i++)
    {
        p = p->next;
        q = q->next;
    }
    p->next = q->next;
    free(q);
}
void deleteWithRoll(node *start, int r)
{
    node *p = start, *q = start->next;
    while(q->next != NULL && q->roll_number != r)
    {
        p = p->next;
        q = q->next;
    }
    if (q->roll_number == r)
    {
        p->next = q->next;
        free(q);
    }
    
}

int main()
{
    node *head;
    node *second;
    node *third;
    node *fourth;

    head = (node *)malloc(sizeof(node));
    second = (node *)malloc(sizeof(node));
    third = (node * )malloc(sizeof(node));
    fourth = (node *)malloc(sizeof(node));

    head->roll_number = 5;
    strcpy(head->name,"Nitin Dhiman");
    head->next = second;

    second->roll_number = 15;
    strcpy(second->name, "Kushi Dutta");
    second->next = third;

    third->roll_number = 45;
    strcpy(third->name,"Rishabh Kamboj");
    third->next = fourth;

    fourth->roll_number = 25;
    strcpy(fourth->name, "Anuj Singla");
    fourth->next = NULL;

    printf("List before deletion:-");
    linkedlistTraversal(head);

    printf("\n\nSelect one of the deletion operation:\n");
    printf("1.Delete at the beginning\n");
    printf("2.Delete at the end\n");
    printf("3.Delete at an index\n");
    printf("4.Deleting the element with a given value from the linked list\n");
    
   int option; 
   scanf("%d",&option);
   if (option == 1)
     {   
        head = deleteAtBeginning(head);
        printf("\nUpdated List after operation is:\n");
        linkedlistTraversal(head);
        printf("\nProgram Exit..");
     }

    else if(option == 2)
    {
        deleteAtEnd(head);
        printf("\nUpdated List after operation is:\n");
        linkedlistTraversal(head);
        printf("\nProgram Exit..");
    }
    else if(option == 3)
    {
        int index;
        printf("Note:- Index starts from 0 and wrong index leads to segmentation fault :/");
        printf("\nEnter the index at which you want to delete the node:\n");
        scanf("%d",&index);
        deleteAtIndex(head,index);
        printf("\nUpdated List after operation is:\n");
        linkedlistTraversal(head);
        printf("\nProgram Exit..");  
    }
    else if(option == 4)
    {
        int roll;
        printf("\nEnter the roll number to delete the node:\n");
        scanf("%d",&roll);
        deleteWithRoll(head,roll);
        printf("\nUpdated List after operation is:\n");
        linkedlistTraversal(head);
        printf("\nProgram Exit..");
    }
    else
        printf("Wrong Option Selected. Exiting :)\n");
      
}
