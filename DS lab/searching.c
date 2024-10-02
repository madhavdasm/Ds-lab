#include <stdio.h>
int n, i, j, a[10], start = 0, end = 0, key, min, temp,
mid, opt;
void sort() {
for (i = 0; i < n - 1; i++) {
min = i;
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

void linear_search() {
int flag = 0;
printf("\nEnter the element you want to search:");
scanf("%d", &key);
for (i = 0; i < n; i++) {
if (a[i] == key) {
flag = 1;
break;
}
}
if (flag == 1) {
printf("Element found at %d!!",i+1);
} else {
printf("Element not found!!");
}
}

void binary_search() {
int start = 0;
sort();
printf("\nEnter the element you want to search:");
scanf("%d", &key);
end = n-1;
mid = (start + end) / 2;
while (start <= end&&key!=a[mid]) {
if (key > a[mid]) {
  start=mid+1;
} 
else{
end = mid - 1;
}
mid = (start + end) / 2;
}

if (key!=a[mid]) {
printf("Element not found!!");
} 
else {
printf("Element found at %d",mid+1);
}
}


void display() {
for (i = 0; i < n; i++) {
printf("%d ", a[i]);
}
}
int main() {
printf("Enter the limit:");
scanf("%d", &n);
printf("Enter the elements:");
for (i = 0; i < n; i++) {
scanf("%d", &a[i]);
}
printf("\n-----MENU-----\n1) Linear Search\n2)Binary Search\n3) Display\n4) Exit\n");
do {
printf("\nEnter your choice (1-4): ");
scanf("%d", &opt);
switch (opt) {
case 1:
linear_search();
break;
case 2:
binary_search();
break;
case 3:
display();
break;
case 4:
printf("Exiting the program.\n");
break;
default:
printf("Invalid choice. Please enter a validoption.\n");
}
} while (opt != 4);
return 0;
}
