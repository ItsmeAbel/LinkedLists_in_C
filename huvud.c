#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "driv.h"
#include "list.h"
#include "node.h"

//node* is pointer to a node while node** is a pointer to the pointer of a node

int main(){
	node* head = NULL;
		head = insertAtBeginning(head, 3);
		head = insertAtBeginning(head, 2);
		head = insertAtBeginning(head, 1);
	int memA = 256;
	int xit = 0;
	char *ct;
	ct = malloc(memA * sizeof *ct);
	int c;
	int check = 0;
	do{
		printf("\nMENY\n0: Avsluta\n1: Skriv ut listan\n2: Skriv ut listans storlek\n3: Lägg till ett heltal sist i listan\n4: Lägg till ett heltal(valfri plats)\n5: Ta bort ett givet heltal\n6: Ta bort ett heltal(valfri plats)\n7: Töm listan\n8: Vänd på listan\n9: Skifta listan ett sten åt vänster(och lägg första heltalet sist)\n10: Skifta listan ett steg åt höger(och lägg sista heltalet först)\n11: Sortera listan (lägsta först)\n12: Skriv ut startadress för listan\n");
		printf("\nGör ditt val (börja med 1): ");

		ct = realloc(ct, memA * sizeof *ct);
		fgets(ct, sizeof(ct), stdin);

		if(sscanf(ct, "%d", &c) != 1){ //returnerar 1 om c är en int
			c = -1;
		}
		ct = realloc(ct, sizeof(*ct)*strlen(ct));

		switch (c){
			case 0:
				printf("Programmet har avslutats \n");
				xit = 1;
				break;

			case 1:

				printf("Skriver ut listan\n");
				// Insert some nodes at the beginning

				printLinkedList(head);
				check = 1;
				break;

			case 2:

				LinkedListSize(head);

				break;

			case 3:

				head = addAtEnd(head);
				break;

			case 4:
				head = addAnywhere(head);

				break;

			case 5:

				head = removeElem(head);
				break;

			case 6:
				head = removeAtPosition(head);

				break;

			case 7:
				head = emptyList(head);
				break;

			case 8:
				head = reverseList(head);
				break;

			case 9:
				head = shiftLeft(head);
				break;

			case 10:
				head = shiftRight(head);
			break;
			case 11:
			head = sortList(head);

			break;
			case 12:

			printStartAdress(head);

			break;
			default:
				printf("Ogiltigt val. \n");
			}

			// Clear the input buffer
			while (getchar() != '\n');
	}while(xit != 1);
	free(ct);


	return 0;
}
