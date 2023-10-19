#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "driv.h"
#include "list.h"
#include "node.h"

//printar ut listans
void printLinkedList(node* head){
  // Print the linked list
  printf("LL: \n");
  printList(head);

};

//beräknar listans storlek
void LinkedListSize(node* head){

  int size = countSize(head);
  // Print the linked list
  printf("LL storlek: %d\n", size);

};
//Lägger heltal sist i listans
node* addAtEnd(node* head){
  int input, placebo;
  printf("Vilken heltal ska läggas sist på listan?\n");
  scanf("%d", &input);
  return addEndNode(head, input);
}

//lägger heltal på valfri platsen
node* addAnywhere(node* head){
  int data, pos;
  printf("Vilken plats ska talet läggas i?(start från 0)\n");
  scanf("%d", &pos);
  printf("Vilket tal ska läggas?\n");
  scanf("%d", &data);
  return insertInLL(head, data, pos);
}

//removeElement
node* removeElem(node* head){
  int data;
  printf("Vilket tal ska tas bort?\n");
  scanf("%d", &data);
  return removeElemFromLL(head, data);
}
//tar bort från valfri platsen
node* removeAtPosition(node* head){
  int pos;
  printf("Vilken plats ska tas bort?\n");
  scanf("%d", &pos);
  return removeFromLL(head, pos);
}

//tömmer listan
node* emptyList(node* head){
  return emptyLL(&head);
}

//vänder på listan
node* reverseList(node* head){
  return reverseListLL(&head);
}
//skiftar listan ett steg mot vänster
node* shiftLeft(node* head){
  return shiftLeftLL(head);
}

//skiftar listan ett steg mot höger
node* shiftRight(node* head){
  return shiftRightLL(head);
}

//sorterar listan
node* sortList(node* head) {
  return bubbleSort(head);
}

//printar ut startadressen till listan
void printStartAdress(node* head){
  printStartAdressLL(head);
}
//returnera elementet på en viss plats i listans

//kollar om en element finns eller intee

//returnera platsen för första förekomst av ett etlement

//lägg till ett element på en viss plats i en listan

//ta bort elementet på viss platsen

//sortera elementen i listan(lägst först)
