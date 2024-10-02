#include <stdio.h>
int n, i, j, temp, a[15];
void selectionSort() {
for (i = 0; i < n - 1; i++) {
int min = i;
for (j = i + 1; j < n; j++) {
if (a[j] < a[min]) {
min = j;
}
}
temp = a[i];
a[i] = a[min];
a[min] = temp;
}
}


void bubbleSort() {
for (i = 0; i < n - 1; i++) {
for (j = 0; j < n - 1 - i; j++) {
if (a[j] > a[j + 1]) {
temp = a[j];
a[j] = a[j + 1];
a[j + 1] = temp;
}
}
}
}


void insertionSort() {
for (i = 1; i < n; i++) {
for (j = i; j > 0; j--) {
if (a[j] < a[j - 1]) {
temp = a[j];
a[j] = a[j - 1];
a[j - 1] = temp;
}
}
}
}


void display() {
printf("\nSorted Array:\n");
for (i = 0; i < n; i++) {
printf("%d ", a[i]);
}
printf("\n");
}


int main() {
int choice;
printf("\n----- MENU -----\n1) Selection Sort\n2)Bubble Sort\n3) Insertion Sort\n4) Display SortedArray\n5) Exit\n");
do {
printf("Enter your choice (1-5): ");
scanf("%d", &choice);
switch (choice) {
case 1:
case 2:
case 3:
printf("Enter the size of the array (max 15):");
scanf("%d", &n);
printf("Enter the array elements:\n");
for (i = 0; i < n; i++) {
scanf("%d", &a[i]);
}
if (choice == 1) {
selectionSort();
display();
printf("\n");
} else if (choice == 2) {
bubbleSort();
display();
printf("\n");
} else if (choice == 3) {
insertionSort();
display();
printf("\n");
}
break;
case 4:
display();
printf("\n");
break;
case 5:
printf("Exiting the program.\n");
break;
default:
printf("Invalid choice. Please enter a validoption.\n");
}
} while (choice != 5);
return 0;
}
