#include "node.h"
#include <stdio.h>
#include <stdlib.h>
#include "stdio.h"
#include "list.h"

node* createNode(int data){
	  node* newNode = (node*)malloc(sizeof(node));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    newNode->el = data;
    newNode->next= NULL;
    return newNode;
}

node* insertAtBeginning(node* head, int data){
    node* newNode = createNode(data);
    newNode->next = head;
    head = newNode;
		return head;
}

// Function to print the linked list
void printList(node* head){
    node* current = head;
		if(isEmpty(head)){
			printf("Listan är tom\n");
		}else{
			while (current != NULL) {
					printf("%d -> ", current->el);
					current = current->next;
			}
			printf("NULL\n");
		}
}


//lägger taö sist på listan
node* addEndNode(node* head, int data){
	node* newNode = createNode(data);
	if (isEmpty(head)) {
			head = newNode;
			return head;
	}

	node* current = head;
	while (current->next != NULL) {
			current = current->next;
	}

	current->next = newNode;

	return head;
}
//Lägger tal på valfri platsen
node* insertInLL(node* head, int data, int pos){
		node* newNode = createNode(data);
		if (isEmpty(newNode) || pos < 0) {
         printf("Ogiltig val\n");
         return head;
     }


     if (pos == 0) {
         return insertAtBeginning(head, data);
     }


     node* current = head;
		 node* previous = NULL;
     int count = 0;

     while (!isEmpty(current) && count < pos){
		 		previous = current;
				current = current->next;
				count++;
     }

		 //utanför rangen. töm nya noden
		if(count < pos){
			free(newNode);
			return head;
		}

		// lägg till noden på position
		previous->next = newNode;
		newNode->next = current;

		return head;
}
//tar bor element
node* removeElemFromLL(node* head, int data){
    //node* current = head;
    //node* previous = NULL;

		if (isEmpty(head)){
        // om lilstan är tomt

				return NULL;
    }

		//om första elementet ska tas bort
		if(head->el == data){
			node* temp = head;
			head = head->next;
			free(temp);

			return head;
		}

    node* current = head;
    while (!isEmpty(current->next) && current->next->el != data) {
        current = current->next;
    }

    if (!isEmpty(current->next)) {
        // Remove the node containing the value.
        node* temp = current->next;
        current->next = temp->next;
        free(temp);
    }

		return head;

}
//tar bort tal från valfri plats
node* removeFromLL(node* head, int position){
	if (position < 0) {
        printf("Ogiltig val\n");
        return head;
    }

    if (isEmpty(head)) {
        printf("listan är tom\n");
        return head;
    }

    if (position == 0) {
        node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }

    node* current = head;
    node* previous = NULL;
    int count = 0;

    while (!isEmpty(current) && count < position) {
        previous = current;
        current = current->next;
        count++;
    }

    if (isEmpty(current)) {
        printf("Ogiltig val\n");
        return head;
    }

    previous->next = current->next;
    free(current);

		return head;
}

//tömmer listan
node* emptyLL(node** head){
  while (*head != NULL) {
    node* temp = *head;
    *head = (*head)->next;
    free(temp);
		}

		return NULL;
}

//vänder på listan
node* reverseListLL(node** head) {
    node* prev = NULL;
    node* current = *head;
    node* next = NULL;

    while (current != NULL) {
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }

    return prev;
}

//beräknar listans storlek
int countSize(node* head) {
	int count = 0;
	node* current = head;
	while (current != NULL) {
			count++;
			current = current->next;
	}
	return count;
}

//skiftar listan ett steg åt vänster och sätter första elementet sist
node* shiftLeftLL(node* head){
	if(isEmpty(head) || head->next == NULL){ //om listan är tom eller innehåller endast ett element
		return head;
	}

	node* current= head;
	head = head->next; // flytta headen till nästa plats

	node* temp = head;
	while(temp->next != NULL){
		temp=temp->next;
	}

	temp->next = current;
	current->next = NULL;
	return head;
}

node* shiftRightLL(node* head){
	if(isEmpty(head) || head->next == NULL){ //om listan är tom eller innehåller endast ett element
		return head;
	}

  node* current = head;
  node* previous = NULL;

//current kommer ha sista platsen och previous kommer ha näst sista platsen efter loopen
  while (current->next != NULL) {
      previous = current;
      current = current->next;
  }

  previous->next = NULL; // sätta null efter näst sista elementet
  current->next = head; // flytta sista elementet till först
  head = current; // sätt den nya elementet till head

	return head;
}

//sorterat listan med bubblesort
node* bubbleSort(node* head) {
    if (isEmpty(head) || head->next == NULL) {
        // The list is empty or has only one element, it's already sorted.
        return head;
    }

    int swapped;
    node* temp;

    do {
        swapped = 0;
        node* current = head;
        node* previous = NULL;

				//loop through the list untill we find n1 is bigger than n2
        while (current->next != NULL) {
            if (current->el > current->next->el) { //om n1 är större än n2, byt plats med dem
                // Swap the data values
                int tempData = current->el;
                current->el = current->next->el;
                current->next->el = tempData;
                swapped = 1;
            }

            previous = current;
            current = current->next;
        }
    } while (swapped);

    return head; // Return the new head.
}

//kollar om listan är tom eller insertAtBeginning
int isEmpty(node* head){
	if (head == NULL) {
		return 1;
	}else{
		return 0;
	}
}
//returnera elementet på en viss plats i listans
int returnEl(node* head, int position){
	if (position < 0) {
        printf("Ogiltig val\n");
        return 0;
  }

	int count = 0;

	node* current = head;
	while (!isEmpty(head)) {
		if (count == position) {
			return current->el;
		}

		current = current->next;
		count++;
	}


	return 0;
}

//printar ut start address till listan
void printStartAdressLL(node* head){

	printf("startadress till listan är: %p\n", (void*)head); //%p andvänds för att printa ut pointer

}
//kollar om en element finns eller intee

//returnera platsen för första förekomst av ett etlement

//lägg till ett element på en viss plats i en listan

//ta bort elementet på viss platsen

//sortera elementen i listan(lägst först)
