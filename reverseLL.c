#include<stdio.h> 
#include<stdlib.h> 
  
/* Linked List building Node */
struct Node 
{ 
    int data; 
    struct Node* next; 
}; 
  
/* Function to reverse the linked list */
static void reverse(struct Node** head_ref) 
{ 
    struct Node* prev   = NULL; 
    struct Node* current = *head_ref; 
    struct Node* next = NULL; 
    while (current != NULL) 
    {         
		next  = current->next;   
        current->next = prev;    
        prev = current; 
        current = next; 
    } 
    *head_ref = prev; 
} 
  
/* Function to push a node */
void push(struct Node** head_ref, int new_data) 
{ 
    struct Node* new_node = 
            (struct Node*) malloc(sizeof(struct Node));            
    new_node->data  = new_data; 
    new_node->next = (*head_ref);     
    (*head_ref)    = new_node; 
} 
  
/* Function to print linked list */
void printList(struct Node *head) 
{ 
    struct Node *temp = head; 
    while(temp != NULL) 
    { 
        printf("%d  ", temp->data);     
        temp = temp->next;   
    } 
} 
  
//test driver program
int main() 
{ 
    //create Linked List
    struct Node* head = NULL; 
     push(&head, 10); 
     push(&head, 30); 
     push(&head, 37);  
     push(&head, 71);       
      
     printf("Test linked list\n"); 
     printList(head);     
     //Reverse it
	 reverse(&head);                       
     printf("\nReversed Linked list \n"); 
     printList(head);     
     
	 return 0;
}

