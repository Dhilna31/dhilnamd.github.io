// C program for the all operations in
// the Doubly Linked List
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Linked List Node
struct node {
	char info[30];
	struct node *prev, *next;
};
struct node* start = NULL;

// Function to traverse the linked list
void traverse()
{
	// List is empty
	if (start == NULL) {
		printf("\nplaylist is empty\n");
		return;
	}
	// Else print the Data
	struct node* temp;
	temp = start;
	while (temp != NULL) {
		printf("song = %s\n", temp->info);
		temp = temp->next;
	}
}

// Function to insert at the front
// of the linked list
void insertAtFront()
{
	char song[30];
	struct node* temp;
	temp = (struct node*)malloc(sizeof(struct node));
	printf("\nEnter song to be inserted: ");
	scanf("%s",song);
	strcpy(temp->info, song);
	temp->prev = NULL;
   
	// Pointer of temp will be
	// assigned to start
	temp->next = start;
	if(start!=NULL)
	    start->prev = temp;
	start = temp;
}

// Function to insert at the end of
// the linked list
void insertAtEnd()
{
	char song[30];
	struct node *temp, *trav;
	temp = (struct node*)malloc(sizeof(struct node));
	temp->prev = NULL;
	temp->next = NULL;
	printf("\nEnter song to be inserted: ");
	scanf(" %[^\n]", song);
	strcpy(temp->info, song);
	temp->next = NULL;
	trav = start;

	// If start is NULL
	if (start == NULL) {

		start = temp;
	}

	// Changes Links
	else {
		while (trav->next != NULL)
			trav = trav->next;
		temp->prev = trav;
		trav->next = temp;
	}
}

void deleteFirst()
{
	struct node* temp;
	if (start == NULL)
		printf("\nList is empty\n");
	else {
		temp = start;
		start = start->next;
		if (start != NULL)
			start->prev = NULL;
		free(temp);
	}
	printf("\nsong is deleted");
}

// Function to delete from the end
// of the linked list
void deleteEnd()
{
	struct node* temp;
	if (start == NULL)
		printf("\nList is empty\n");
	else{
	    if (start->next == NULL)
		    start = NULL;
	    else{
	        temp = start;
        	while (temp->next != NULL)
		    {
		        temp = temp->next;
		    }
	    	temp->prev->next = NULL;
		  //  free(temp);
	    }
	}

}

// Function to delete  specified
// song from the linked list
void deleteSong()
{
	int pos, i = 1;
	char song[30];
	struct node *temp;
	temp = start;

	if (start == NULL)
		printf("\nList is empty\n");
	else
	{
	    printf("Enter song to be deleted : ");
	    scanf(" %[^\n]", song);
	   if(strcmp(start->info,song) == 0 && start->next == NULL)
		{
		    start=NULL;
		}
	else if(strcmp(start->info,song) == 0){
	    start=start->next;
	    start->prev=NULL;
	}
	else{
        while (temp !=NULL && strcmp(temp->info,song) != 0) {
			temp = temp->next;
		}
		if(temp == NULL)
		{
		    printf("Song not found!\n");
		}
		else if(temp->next == NULL)
		{
		    temp->prev->next=NULL;
		}
		else{
		    temp->prev->next = temp->next;
		    temp->next->prev = temp->prev;
        }
	} 
	}
	 
}

// Driver Code
int main()
{
	int choice;
	while (1) {

		printf("\n\t1 To see playlist\n");
		printf("\t2 For inserting a song at"
			" starting\n");
		printf("\t3 For inserting a song at"
			" end\n");
		printf("\t4 For deleting "
			"first song\n");
		printf("\t5 For deleting "
			"last song\n");
		printf("\t6 For deleting a specific song\n");
		printf("\t7 To exit\n");
		printf("\nEnter Choice :\n");
		scanf("%d", &choice);

		switch (choice) {
		case 1:
			traverse();
			break;
		case 2:
			insertAtFront();
			break;
		case 3:
			insertAtEnd();
			break;
		case 4:
			deleteFirst();
			break;
		case 5:
			deleteEnd();
			break;
		case 6:
			deleteSong();
			break;
		case 7:
			exit(1);
			break;
		default:
			printf("Incorrect Choice. Try Again \n");
			continue;
		}
	}
	return 0;
}
