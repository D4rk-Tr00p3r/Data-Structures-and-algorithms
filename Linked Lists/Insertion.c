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

node * insertAtBeginning(node *start,int a,char *b)
{   
    node *ptr = (node*)malloc(sizeof(node));
    strcpy(ptr->name, b);
    ptr->roll_number = a;
    ptr->next = start;
    return ptr; //returning the new head of the list
}

void insertAtEnd(node *start,int a,char *b)
{   
    node * ptr = (node *)malloc(sizeof(node));
    strcpy(ptr->name,b);
    ptr->roll_number = a;
    
    node *p = start;
    while(p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
}
void insertAtIndex(node *start,int a,char *b,int n) //index starts from 0
{
    node * ptr = (node *)malloc(sizeof(node));
    strcpy(ptr->name,b);
    ptr->roll_number = a;

    node *p = start;

    int i = 0;
    while(i != n-1)
    {
        p = p->next;
        i++;
    }
    ptr->next = p->next;
    p->next = ptr;

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

    printf("List before insertion:-");
    linkedlistTraversal(head);

    printf("\n\nSelect one of the insertion operation:\n");
    printf("1.Inset at the beginning\n");
    printf("2.Insert at the end\n");
    printf("3.Insert at an index\n");
    
   int option; 
   scanf("%d",&option);
   if (option == 1)
     {   
        int roll;
        char new_name[100];
        char temp;
        printf("Enter roll number: ");
        scanf("%d",&roll);
        printf("Ente the new name: ");
        scanf("%c",&temp); // temp statement to clear buffer
        scanf("%[^\n]",&new_name[0]);  //The format specifier "%[^\n]" tells to the compiler that read the characters until "\n" is not found.
        /*
        //Another way of taking input with spaces
        scanf("%c",&temp); // temp statement to clear buffer
	    fgets(name,30,stdin);
        */
        head = insertAtBeginning(head,roll,new_name);
        printf("\nUpdated List after operation is:\n");
        linkedlistTraversal(head);
        printf("\nProgram Exit..");
     }

    else if(option == 2)
    {
        int roll;
        char new_name[100];
        char temp;
        printf("Enter roll number: ");
        scanf("%d",&roll);
        printf("Ente the new name: ");
        scanf("%c",&temp); // temp statement to clear buffer
        scanf("%[^\n]",&new_name[0]);  //The format specifier "%[^\n]" tells to the compiler that read the characters until "\n" is not found.
        /*
        //Another way of taking input with spaces
        scanf("%c",&temp); // temp statement to clear buffer
	    fgets(name,30,stdin);
        */
        insertAtEnd(head,roll,new_name);
        printf("\nUpdated List after operation is:\n");
        linkedlistTraversal(head);
        printf("\nProgram Exit..");
    }
    else if(option == 3)
    {
        int roll;
        char new_name[100];
        char temp;
        int index;
        printf("Note:- Index starts from 0 and wrong index leads to segmentation fault :/");
        printf("\nEnter the index at which you want to add the node:\n");
        scanf("%d",&index);
        printf("Enter roll number: ");
        scanf("%d",&roll);
        printf("Ente the new name: ");
        scanf("%c",&temp); // temp statement to clear buffer
        scanf("%[^\n]",&new_name[0]);  //The format specifier "%[^\n]" tells to the compiler that read the characters until "\n" is not found.
        /*
        //Another way of taking input with spaces
        scanf("%c",&temp); // temp statement to clear buffer
	    fgets(name,30,stdin);
        */
        insertAtIndex(head,roll,new_name,index);
        printf("\nUpdated List after operation is:\n");
        linkedlistTraversal(head);
        printf("\nProgram Exit..");
        
    }
    else
        printf("Wrong Option Selected. Exiting :)\n");
      
}
