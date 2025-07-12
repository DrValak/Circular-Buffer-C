// Circular Buffer

#include <stdio.h>
#include <stdlib.h>

typedef struct { // create struct for Buffer
	int dados[10]; // data - size of array , 10
	int head; // head of the array
	int tail; // tail of the array
	int full; // variable to check if it is full
} CircularBuffer;

void startBuffer(CircularBuffer *buffer) {
	// All starts with 0
	buffer -> head = 0;
	buffer -> tail = 0;
	buffer -> full = 0;
}

int insertData(CircularBuffer *buffer, int insertion) {

	if (buffer -> full) { // check if it is full
		printf("Buffer is full!\n"); 
		return 1;
	}

	buffer -> dados[buffer -> tail] = insertion; // insert data

	buffer -> tail = (buffer -> tail + 1) % 10; // increment tail in circular

	if (buffer -> tail == buffer -> head) {
		buffer -> full = 1; // buffer it's full
	}

	return 0;
}

int removeData(CircularBuffer *buffer, int *removed_value) {

	if (buffer -> head == buffer -> tail && buffer -> full == 0) {
		printf("Buffer is empty!\n");
		return 1;
	}

	*removed_value = buffer -> dados[buffer -> head]; // Store the remove value

	buffer -> head = (buffer -> head + 1) % 10; // increment head in circular

	buffer -> full = 0;

	return 1;
}

int showData(CircularBuffer *buffer) {

	int count = 0;

	if (buffer -> full) {
		count = 10;
	}

	else if (buffer -> tail >= buffer -> head) {
		count = buffer -> tail - buffer -> head;
	}

	else {
		count = 10 - buffer -> head + buffer -> tail;
	}

	int idx = buffer -> head;
	for (int i = 0; i < count; i++) {
		printf("%d\n",buffer -> dados[idx]);
		idx = (idx + 1) % 10;
	}

	return 0;
}

int main () {

	CircularBuffer buffer;
	startBuffer(&buffer);

	printf("Inserting values from 1 to 9.\n");
	for (int i = 1; i < 10; i++) {
		insertData(&buffer,i);
	}

	printf("Showing data from buffer\n");
	showData(&buffer);

	printf("Testing remove function.\n");
	int num_removed;
	
	printf("How many elements do you want to remove?  ");
	fflush(stdout);
	scanf("%d",&num_removed);

	for (int i = 0; i < num_removed; i++) {
		int removed_value;
		if (removeData(&buffer,&removed_value) == 0) {
			printf("Removed: %d\n",removed_value);
		}
	}

	showData(&buffer);

	printf("Testing insert function.\n");
	insertData(&buffer,76);
	insertData(&buffer,43);
	insertData(&buffer,99);
	insertData(&buffer,23); // this value will not be in the buffer
	showData(&buffer);

	return 0;

}