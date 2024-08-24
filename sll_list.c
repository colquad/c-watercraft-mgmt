#include <stdio.h>
#include <stdlib.h>
#include "sll_list.h"


int printMenu( ) {
	//Printing menu
	int choice;
	printf("\n");
	printf("1. load inventory of watercraft from file\n");
	printf("2. add additional watercraft to front of list\n");
	printf("3. add additional watercraft to end of list\n");
	printf("4. number of watercraft in inventory\n");
	printf("5. print inventory of watercraft\n");
	printf("6. print specs of chosen watercraft\n");
	printf("7. delete chosen watercraft\n");
	printf("8. search watercraft by type\n");
	printf("9. search watercraft by motor type\n");
	printf("10. sort watercraft by price\n");
	printf("11. total asset value in inventory\n");
	printf("12. quit program\n");
	scanf("%d", &choice);
	
	//Returns user input
	return choice;
}


list_t *newList( ) {
	//Allocate memory
	list_t *w = (list_t*)malloc(sizeof(list_t));
	w->head = NULL;
	w->tail = NULL;
	w->size = 0;
	//Returns the list
	return w;
}


void listInit( list_t *list, FILE *inFile ) {
	//Allocate memory
	watercraft_t * init = (watercraft_t*)malloc(sizeof(watercraft_t));
	init = new_waterCraft(inFile);

	if (list->head == NULL) {
		list->head = init;
		list->tail = list->head;
		list->size += 1;
	}
	else {
		list->tail->next = init;
		list->tail = list->tail->next;
		list->size += 1;
	}
}


void initializeFromFile( list_t *list, FILE *inFile ) {
	//While not at end of file
	while (!feof(inFile)) {
		listInit(list, inFile);
	}
}


watercraft_t *new_waterCraft( FILE *inFile ) {
	//Allocate memory
	watercraft_t *newNode = (watercraft_t *)malloc(sizeof(watercraft_t));

	//Check if node exists
	if (newNode == NULL) {
		printf("Node allocation failure\n");
		exit( -1 );
	}

	//Scan in the watercraft info
	fscanf(inFile, "%15[^,\n\t], %20[^,\n\t], %30[^,\n\t], %d, %15[^,\n\t], %d, %25[^,\n\t], %d, %lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf, %lf\n",
			newNode->type, newNode->make, newNode->model, &newNode->propulsion,
			newNode->engine, &newNode->hp, newNode->color, &newNode->length,
			&newNode->base_price, &newNode->total_price, &newNode->extras.bimini,
			&newNode->extras.towbar, &newNode->extras.stereo, &newNode->extras.table,
			&newNode->extras.gps, &newNode->extras.anchor, &newNode->extras.paddles);
	newNode->next = NULL;
	
	return newNode;
}


void addToFront( list_t *list ) {
	//Allocate memory
	watercraft_t * newNode = (watercraft_t*)malloc(sizeof(watercraft_t));

	//Set a price so we can add it at the end
	double priceTot = 0;

	printf("Enter watercraft type: ");
	fscanf(stdin, " %15[^\n]", newNode->type);

	printf("Enter watercraft make: ");
	fscanf(stdin, " %20[^\n]", newNode->make);

	printf("Enter watercraft model: ");
	fscanf(stdin, " %30[^\n]", newNode->model);

	printf("Enter 0 for no motor, 1 for out-board, 2 for in-board"
			": ");
	fscanf(stdin, " %d", &newNode->propulsion);

	printf("Enter engine make: ");
	fscanf(stdin, " %15[^\n]", newNode->engine);

	printf("How much horsepower does the engine have? ");
	fscanf(stdin, " %d", &newNode->hp);

	printf("Enter color of watercraft: ");
	fscanf(stdin, " %25[^\n]", newNode->color);

	printf("Length of watercraft: ");
	fscanf(stdin, " %d", &newNode->length);

	printf("Base price of watercraft: ");
	fscanf(stdin, " %lf", &newNode->base_price);
	priceTot += newNode->base_price;

	printf("Cost of bimini: ");
	fscanf(stdin, " %lf", &newNode->extras.bimini);
	priceTot += newNode->extras.bimini;

	printf("Cost of towbar: ");
	fscanf(stdin, " %lf", &newNode->extras.towbar);
	priceTot += newNode->extras.towbar;

	printf("Cost of stereo: ");
	fscanf(stdin, " %lf", &newNode->extras.stereo);
	priceTot += newNode->extras.stereo;

	printf("Cost of table: ");
	fscanf(stdin, " %lf", &newNode->extras.table);
	priceTot += newNode->extras.table;
		
	printf("Cost of anchor: ");
	fscanf(stdin, " %lf", &newNode->extras.anchor);
	priceTot += newNode->extras.anchor;

	printf("Cost of paddles: ");
	fscanf(stdin, " %lf", &newNode->extras.paddles);
	priceTot += newNode->extras.paddles;

	//Update the total price and size
	newNode->total_price = priceTot;
	list->size++;

	newNode->next = list->head;
	list->head = newNode;
}


void addToRear( list_t *list ) {
	//Allocate memory
	watercraft_t * newNode = (watercraft_t*)malloc(sizeof(watercraft_t));
	double priceTot = 0;

	printf("Enter watercraft type: ");
	fscanf(stdin, " %15[^\n]", newNode->type);
	
	printf("Enter watercraft make: ");
	fscanf(stdin, " %20[^\n]", newNode->make);

	printf("Enter watercraft model: ");
	fscanf(stdin, " %30[^\n]", newNode->model);

	printf("Enter 0 for no motor, 1 for out-board, 2 for in-board"
			": ");
	fscanf(stdin, " %d", &newNode->propulsion);

	printf("Enter engine make: ");
	fscanf(stdin, " %15[^\n]", newNode->engine);

	printf("How much horsepower does the engine have?");
	fscanf(stdin, " %d", &newNode->hp);

	printf("Enter color of watercraft: ");
	fscanf(stdin, " %25[^\n]", newNode->color);

	printf("Length of watercraft: ");
	fscanf(stdin, " %d", &newNode->length);

	printf("Base price of watercraft: ");
	fscanf(stdin, " %lf", &newNode->base_price);

	printf("Cost of bimini: ");
	fscanf(stdin, " %lf", &newNode->extras.bimini);

	printf("Cost of towbar: ");
	fscanf(stdin, " %lf", &newNode->extras.towbar);

	printf("Cost of stereo: ");
	fscanf(stdin, " %lf", &newNode->extras.stereo);

	printf("Cost of table: ");
	fscanf(stdin, " %lf", &newNode->extras.table);

	printf("Cost of gps: ");
	fscanf(stdin, " %lf", &newNode->extras.gps);

	printf("Cost of anchor: ");
	fscanf(stdin, " %lf", &newNode->extras.anchor);

	printf("Cost of paddles: ");
	fscanf(stdin, " %lf", &newNode->extras.paddles);

	//Update the total price and size
	newNode->total_price = priceTot;
	list->size++;

	newNode->next = NULL;
	list->tail->next = newNode;
	list->tail = newNode;
}


void printList( list_t *list ) {
	watercraft_t * current = list->head;
	int numItems = list->size;

	printf("Watercraft in list: \n");
	printf("\n");

	//Traverse through list printing each one
	for (int i = 1; i <= numItems; ++i) {
		printf("%2d. %s \t%-20s %-23s %-10s %5dhp   %-17s %5dft  $%10.2lf \n",
				i, current->type, current->make, current->model, current->engine,
				current->hp, current->color, current->length, current->total_price);
		//Check if there is more to print
		if (current->next)
			current = current->next;
	}
	printf("\n");
}


void printSpecs( list_t *list ) {
	watercraft_t * w = list->head;
	int choice;

	//Calls printList
	printList(list);

	printf("Enter the # of the watercraft for the specs: ");
	fscanf(stdin, "%d", &choice);

	//Check if the option is valid
	if (choice < 1 || choice > list->size) {
		printf("Error: Invalid input!\n");
		return;
	}

	for (int i = 0; i < choice - 1; ++i)
		w = w->next;

	printf("%s %s %s %s %dhp %s %dft $ %lf\n", 
			w->type, w->make, w->model, w->engine, w->hp, w->color,
			w->length, w->total_price);

	//Different types of motors
	if (w->propulsion == 0) {
		printf("No motor\n");
	}
	else if (w->propulsion == 1) {
		printf("In-board motor\n");
	}
	else if (w->propulsion == 2) {
		printf("Out-board motor\n");
	}

	printf("Base price: $ %.2lf\n", w->base_price);

	if (w->extras.bimini > 0) 
		printf("Bimini: $ %.2lf\n", w->extras.bimini);
	
	if (w->extras.towbar > 0) 
		printf("Towbar: $ %.2lf\n", w->extras.towbar);
	
	if (w->extras.stereo > 0) 
		printf("Stereo: $ %.2lf\n", w->extras.stereo);
	
	if (w->extras.table > 0) 
		printf("Table: $ %.2lf\n", w->extras.table);
	
	if (w->extras.gps > 0)
		printf("GPS: $ %.2lf\n", w->extras.gps);

	if (w->extras.anchor > 0) 
		printf("Anchor: $ %.2lf\n", w->extras.anchor);
	
	if (w->extras.paddles > 0)
		printf("Paddles: $ %.2lf\n", w->extras.paddles);
}


void deleteWatercraft( list_t *list ) {
	watercraft_t * temp = list->head;
	watercraft_t * delete = list->head;
	int choice;
	int iterate = 0;

	//Print the list
	printList(list);

	printf("Enter the # of the watercraft to delete from inventory: ");
	fscanf(stdin, "%d", &choice);

	//Check if input is valid
	if (choice < 1 || choice > list->size) {
		printf("Error: Invalid Input!\n");
		return;
	}
	else {
		//Deletes the node
		while (iterate <= choice - 2) {
			++iterate;
			temp = delete;
			delete = delete->next;
		}

		temp->next = delete->next;	
		list->size -= 1;

		//Free the pointer
		free(delete);
	}
}


int typeInInventory( list_t *list, char whichOne[] ) {
	watercraft_t * search = list->head;

	//Compare strings and if the string is the same return 1
	while (search != NULL) {
		if (strcmp(search->type, whichOne) == 0)
			return 1;

		search = search->next;
	}
	//Returns 0 if that type is not found
	return 0;
}


int motorInInventory( list_t *list, int whichOne ) {
	watercraft_t * search = list->head;

	//Iterate through and check if the watercraft is 
	while (search != NULL) {
		if (search->propulsion == whichOne)
			return 1;

		search = search->next;
	}

	return 0;
}


void printWatercraftByType( list_t *list, char whichOne[] ) {
	watercraft_t * current = list->head;
	
	//Iterate through and print watercrafts that are of the chosen type
	for (int i = 1; i <= list->size; ++i) {
		if (strcmp(current->type, whichOne) == 0) {
			printf("%2d. %s \t%-20s %-23s %-10s %5dhp  %-17s %5dft $ %10.2lf \n",
					i, current->type, current->make, current->model, current->engine,
					current->hp, current->color, current->length, current->total_price);
		}
		current = current->next;
	}
	printf("\n");
}


void printWatercraftByMotor( list_t *list, int whichOne ) {
	watercraft_t * current = list->head;
	
	//Iterate through and print watercrafts that have chosen motor type
	for (int i = 1; i <= list->size; ++i) {
		if (current->propulsion == whichOne) {
			printf("%2d. %s \t%-20s %-23s %-10s %5dhp  %-17s %5dft $ %10.2lf \n",
					i, current->type, current->make, current->model, current->engine,
					current->hp, current->color, current->length, current->total_price);
		}
		current = current->next;
	}
	printf("\n");
}


void searchByType( list_t *list ) {
	int choice;

	//Scanning in the user input
	printf("Type of watercraft to search for:\n");
	printf("1. pontoon\n");
	printf("2. fishing\n");
	printf("3. sport boat\n");
	printf("4. kayak\n");
	printf("5. canoe\n");
	printf("6. sailboat\n");
	scanf(" %d", &choice);

	//Printing the watercrafts for certain types
	switch(choice) {
		case 1:
			if (typeInInventory(list, "pontoon"))
				printWatercraftByType(list, "pontoon");
			break;
		case 2:
			if (typeInInventory(list, "fishing"))
				printWatercraftByType(list, "fishing");
			break;
		case 3:
			if (typeInInventory(list, "sport boat"))
				printWatercraftByType(list, "sport boat");
			break;
		case 4:
			if (typeInInventory(list, "kayak"))
				printWatercraftByType(list, "kayak");
			break;
		case 5:
			if (typeInInventory(list, "canoe"))
				printWatercraftByType(list, "canoe");
			break;
		case 6:
			if (typeInInventory(list, "sailboat"))
				printWatercraftByType(list, "sailboat");
			break;
		default:
			printf("Invalid input\n");
			break;
	}
	
}


void searchByMotorType( list_t *list ) {
	int choice;
	
	//Scanning in the user input and changing it to match the motor numbers
	printf("Type of motor to search for:\n");
	printf("1. no motor\n");
	printf("2. out-board\n");
	printf("3. in-board\n");
	scanf(" %d", &choice);
	choice -= 1;

	//If there is a watercraft of that type print it
	if (motorInInventory(list, choice) == 1) {
		printWatercraftByMotor(list, choice);
		return;
	}
	else if (motorInInventory(list, choice) == 0) {
		printf("No watercraft found\n");
		return;
	}
}


void printByPrice( list_t *list ) {
	watercraft_t jit[list->size];
	watercraft_t * point = list->head;
	double temp;

	//Copying over the data to array
	for (int i = 0; i < list->size; ++i) {
		jit[i] = *point;
		point = point->next;
	}

	for (int i = 0; i < list->size; ++i) {
		for (int j = 0; j < list->size - i; ++j) {
			if (jit[j].total_price > jit[j+1].total_price) {
				temp = jit[j].total_price;
				jit[j].total_price = jit[j+1].total_price;
				jit[j+1].total_price = temp;
			}
		}
	}

	for (int i = 0; i < list->size; ++i) {
		printf("%2d %s \t%-20s %-23s %-10s %5dhp  %-17s %5dft %10.2lf\n",
				i+1, jit[i].type, jit[i].make, jit[i].model, jit[i].engine,
				jit[i].hp, jit[i].color, jit[i].length, jit[i].total_price);
	}
}


int isEmpty( list_t *list ) {
	//Checks if the head is null, if the head is null then the list is empty
	if (list->head == NULL) {
		return 1;
	}
	else {
		return 0;
	}
}

void TAV( list_t *list ) {
	watercraft_t *w = list->head;
	double priceTot = 0;
	
	priceTot = w->total_price;
	
	//Adding all the prices up to total price
	while (w->next != NULL) {
		w = w->next;
		priceTot += w->total_price;
	}
	printf("Total asset value of all inventory is: $ %.2lf\n", priceTot);
}
