#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "sll_list.h"


int main(int argc, char * argv[]) {
	int choice;
	bool exit;

	//Initializing a new list
	list_t * list = newList();
	
	//Open the file inputted as argv
	FILE* inFP = fopen(argv[1], "r");

	if (inFP == NULL) {
		printf("\nFile is NULL\n\n");
	}

	exit = false;

	while (exit == false) {
		choice =  printMenu();

		switch (choice) {
			case 1:
				initializeFromFile(list, inFP);
				printf("Loaded watercraft from file.\n");
				break;
			case 2:
				if (isEmpty(list))
					printf("Error: List is empty\n");
				else
					addToFront(list);
				break;
			case 3:
				if (isEmpty(list))
					printf("Error: List is empty\n");
				else 
					addToRear(list);
				break;
			case 4:
				if (isEmpty(list))
					printf("Error: List is empty\n");
				else
					printf("There are %d watercraft in the inventory.\n", list->size);
				break;
			case 5:
				if (isEmpty(list))
					printf("Error: List is empty\n");
				else
					printList(list);
				break;
			case 6:
				if (isEmpty(list))
					printf("Error: List is empty\n");
				else
					printSpecs(list);
				break;
			case 7:
				if (isEmpty(list))
					printf("Error: List is empty\n");
				else
					deleteWatercraft(list);
				break;
			case 8:
				if (isEmpty(list))
					printf("Error: List is empty\n");
				else
					searchByType(list);
				break;
			case 9:
				if (isEmpty(list))
					printf("Error: List is empty\n");
				else
					searchByMotorType(list);
				break;
			case 10:
				if (isEmpty(list))
					printf("Error: List is empty\n");
				else
					printByPrice(list);
				break;
			case 11:
				if (isEmpty(list))
					printf("Error: List is empty\n");
				else
					TAV(list);
				break;
			case 12:
				exit = true;
				break;
			default:
				printf("Invalid input\n");
				break;
				
		}
	}
	
	//Close the file
	fclose(inFP);

	//Free all memory
	free(list);

}
