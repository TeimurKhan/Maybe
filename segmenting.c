#include <stdio.h>
#include <stdlib.h>

/* Declarations */
struct WordList;
int init_List(struct WordList **);
int push(struct WordList** , char* );
void printList(struct WordList *); 
void clear_list(struct WordList **);
int getSubString(char *, char *,int, int);
int segment(char *, struct WordList**, char);


/* Building Node of WordList */
struct WordList { 
    char* data; 
    struct WordList* next; 
};

/* Initialize New WordList */
int init_List(struct WordList **head){
	struct WordList* newlist = (struct WordList*) malloc(sizeof(struct WordList));
	if(newlist==NULL){
		printf("%s","Dynamic Memory Failure"); 
		return 1;
	}
	newlist->next=NULL;
	*head=newlist;
	return 0;
}

/* Add/Push new word to WordList */
int push(struct WordList** head_ref, char* new_data){ 
    
	struct WordList* newNode = (struct WordList*) malloc(sizeof(struct WordList));
	if( newNode==NULL){
		printf("%s","Dynamic Memory Error");
	}
    struct WordList* temp = (*head_ref); 
    newNode->data = new_data;
    newNode->next = NULL; 
    temp = (*head_ref);
	while(temp->next != NULL){
		temp = temp->next;
	}
    temp->next = newNode;
	return 0;
}

/* Print WordList */
void printList(struct WordList *head){   
    
	struct WordList *temp = head;
    if(temp == NULL){
        printf("%s","Word List Empty\n");
    }
	else{
		printf("%s","Segmented Sentence:\n\n");
	}
    temp=temp->next;
	while(temp != NULL){ 
        printf("%s", temp->data);
        printf("\n");
        temp = temp->next;
    } 
}

/* Free Memory of List */
void clear_list(struct WordList **head){
	struct WordList *current = (*head);
	struct WordList *following = (*head);
    if(current == NULL){
        printf("%s","Cleared\n");
    }
	while(current != NULL){ 
		following = current->next;
		free(current);
		current	= following;
    }
	*head=NULL;
}

/* Substring function, given indices */
int  getSubString(char *source, char *target,int from, int to){
	
	int length=0;
	int i=0,j=0;
	
	while(source[i++]!='\0')
		length++;
	
	if(from<0 || from>length){
		printf("Invalid \'from\' index\n");
		return 1;
	}
	if(to>length){
		printf("Invalid \'to\' index\n");
		return 1;
	}	
	
	for(i=from,j=0;i<=to;i++,j++){
		target[j]=source[i];
	}
	
	target[j]='\0';
	return 0;	
}

/* Segment Sentence into WordList */
int segment(char* sentence, struct WordList** head_ref, char delimiter){

    int i=0;
	int j=0;
	int start=0;

	if (sentence[0]=='\0'){
	  printf("%s","Empty String\n");
	}
	
	while(1){
		if (sentence[i]==delimiter||sentence[i]=='\0'){
		  
			if (sentence[i]==delimiter&&sentence[i+1]==delimiter){
				//two consecutive spaces (skip)
			}
			else if(sentence[i]==delimiter&&sentence[i+1]=='\0'){
				//end of string (last character white space)
				break;
			}
			else{
				
				char *current_word = (char *) malloc(sizeof(char)*(i-start+1));
				if(current_word==NULL){
					printf("%s","Dynamic Memory Failure");
					return 1;
				}
			  
				if(getSubString(sentence,current_word,start,i-1)==0){
					if(push(head_ref, current_word)==1){
						printf("%s","Dynamic Memory Failure");  
						return 1;				  
					}
					j++;
					start=i+1;
				}
			  
				if(sentence[i]=='\0'){
					//End of String
					break;
				}
			}
		}
		i++;
	}
	
	if (j==0){
		printf("%s", "No words in String");
	}

	return 0;
}

/* Driver Program */
int main(void){
    
	//Enter any string here:
	char* test_string="Test String for Maybe to converting into List of Words";
	//Enter delimiter
	char delimiter=' ';
	
	//Initialize WordList
	struct WordList* segmented = NULL;
	if(init_List(&segmented)!=0){
		printf("%s","Dynamic Memory Failure"); 
		return 1;
	}
	
	//Segment and Print
	if(segment(test_string,&segmented,delimiter)==0){
		printList(segmented);
	}
	
	//Free memory
	clear_list(&segmented);

	return 0;
}