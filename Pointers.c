#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <locale.h>

#define SIZE 100

void bubble_sort(int* array);
void insert_sort(int* items, int count);

int main(void) {
	char str[10] = "start";
	int array[SIZE];
	time_t t1, t2;

	setlocale(LC_ALL, "Rus");
	srand((unsigned int)time(NULL));
	for (int i = 0; i < SIZE; i++) {
		array[i] = rand() % 100;
		printf("%d\t", array[i]);
	}
	printf("\n");
//	bubble_sort(array);
	insert_sort(array, SIZE);

	t1 = time(NULL);
	for (long unsigned t = 0; t<5000000; t++);
	t2 = time(NULL);

	for (int i = 0; i < SIZE; i++)
		printf("%d\t", array[i]);
	printf("\n");

	printf("Время в секундах: %lf\n", difftime(t2, t1));

	do {
		printf("Enter string: ");
		scanf_s("%s", str, (unsigned int) sizeof(str));
		printf("\nThis is your string: %s", str);
	} while (strcmp(str, "quit"));

	return 0;
}

void bubble_sort(int* array) {
	int tmp = 0;

	for(int i = 0; i < SIZE - 1; i++)
		for (int j = 0; j < SIZE - 1 - i; j++) {
			if (array[j] > array[j + 1]) {
				tmp = array[j + 1];
				array[j + 1] = array[j];
				array[j] = tmp;
			}
		}
}

void insert_sort(int* items, int count) {
	int t, j;
	for (int i = 1; i < count; ++i) {
		t = items[i];
		for (j = i - 1; (j >= 0) && (t < items[j]); j--)
			items[j + 1] = items[j];
		items[j + 1] = t;
	}
}