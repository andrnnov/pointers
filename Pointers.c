#include <string.h>
#include <conio.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <locale.h>

#define SIZE 100

int bubble_sort(int array[]);

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
	bubble_sort(array);

	long unsigned t;
	t1 = time(NULL);
	for (t = 0; t<5000000; t++);
	t2 = time(NULL);

	for (int i = 0; i < SIZE; i++)
		printf("%d\t", array[i]);
	printf("\n");

	printf("Время в миллисекундах: %0.4lf\n", difftime(t2, t1));

	do {
		printf("Enter string: ");
		scanf_s("%s", str, (unsigned int) sizeof(str));
		printf("\nThis is your string: %s", str);
	} while (strcmp(str, "quit"));

	return 0;
}

int bubble_sort(int array[]) {
	int tmp = 0;

	for(int i = 0; i < SIZE - 1; i++)
		for (int j = 0; j < SIZE - 1 - i; j++) {
			if (array[j] > array[j + 1]) {
				tmp = array[j + 1];
				array[j + 1] = array[j];
				array[j] = tmp;
			}
		}
	return 0;
}