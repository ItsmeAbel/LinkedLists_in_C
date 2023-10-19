#include "node.h"

#ifndef STRANG_HEADER
#define STRANG_HEADER
node* createNode(int data);
node* insertAtBeginning(node* head, int data);
node* addEndNode(node* head, int data);
void printList(node* head);
int countSize(node* head);
node* insertInLL(node* head, int data, int pos);
node* removeFromLL(node* head, int position);
node* emptyLL(node** head);
node* removeElemFromLL(node* head, int data);
node* reverseListLL(node** head);
int isEmpty(node* head);
node* shiftLeftLL(node* head);
node* shiftRightLL(node* head);
node* bubbleSort(node* head);
void printStartAdressLL(node* head);
#endif
