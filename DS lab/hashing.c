#include <stdio.h>
#include <stdlib.h>
int i, opt;
struct node {
int data;
struct node *next;
} *newnode, *head[10] = {NULL}, *temp, *prev;
int getIndex(int h, int k) {
// Hash function = H(K) = k (mod h)
return k % h;
}
void open_insert(int n, int key) {
newnode = (struct node
*)malloc(sizeof(struct node));
newnode->data = key;
newnode->next = NULL;
int index = getIndex(n, key);
if (head[index] == NULL) {
head[index] = newnode;
} else {
temp = head[index];
while (temp->next != NULL) {
temp = temp->next;
}
temp->next = newnode;
}
}
void open_display(int n) {
for (i = 0; i < n; i++) {
if (head[i] == NULL) {
continue;
} else {
temp = head[i];
printf("index[%d]", i);
while (temp != NULL) {
printf("->%d", temp->data);
temp = temp->next;
}
}
printf("\n");
}

}
void open_delete(int n, int key) {
int index = getIndex(n, key);
if (head[index] == NULL) {
printf("%d is not present in the hashtable!!", key);
} else {
temp = head[index];
prev = NULL;
while (temp != NULL) {
if (temp->data == key) {
if (prev != NULL) {
prev->next = temp->next;
free(temp);
printf("%d is deleted from the array\n", key);
} else {
head[index] = temp->next;
free(temp);
printf("%d is deleted from the array\n", key);
}
break;
}
prev = temp;
temp = temp->next;
}
if (temp == NULL) {
printf("%d is not present in the hash table!!", key);
}
}
}
int open_search(int n, int key) {
int index = getIndex(n, key);
if (head[index] == NULL) {
printf("%d is not present in the hashtable!!", key);
} else {
temp = head[index];
while (temp != NULL) {
if (temp->data == key) {

printf("%d is present in thehashtable!!", key);
return 1;
}
temp = temp->next;
}
printf("%d is not present in the hashtable!!", key);
}
return 0;
}
void openhashing() {
int n, key;
printf("Enter the size of the array:");
scanf("%d", &n);
printf("\n-----MENU-----\n1)insert\n2)delete\n3)search\n4)display\n5)exit");
do {
printf("\nenter your choice:");
scanf("%d", &opt);
if (opt == 1) {
printf("\nEnter the element to insert:");
scanf("%d", &key);
open_insert(n, key);
printf("\n");
open_display(n);
} else if (opt == 2) {
printf("\nEnter the element to delete:");
scanf("%d", &key);
open_delete(n, key);
printf("\n");
open_display(n);
} else if (opt == 3) {
printf("\nEnter the element to search:");
scanf("%d", &key);
open_search(n, key);
} else if (opt == 4) {
printf("\n");
open_display(n);
printf("\n");
} else if (opt != 5) {
printf("Invalid operation!!");
}
} while (opt != 5);

}
void close_insert(int a[], int n, int key) {
int index;
index = getIndex(n, key);
if (a[index] == -1) {
a[index] = key;
} else {
int originalIndex = index;
do {
index = (index + 1) % n;
} while (a[index] != -1 && index !=
originalIndex);
if (index != originalIndex) {
a[index] = key;
} else {
printf("Hash table is full. Unable to insert %d.\n", key);
}
}
}
void close_display(int a[], int n) {
for (i = 0; i < n; i++) {
if (a[i] != -1) {
printf("index[%d] = %d\n", i, a[i]);
}
}
}
void close_delete(int a[], int n, int key) {
int index = close_search(a, n, key);
if (index == -1) {
printf("%d is not present in thehashtable..", key);
} else {
printf("%d is deleted from the hashtable",key);
a[index] = -1;
}
}
int close_search(int a[], int n, int key) {
int index = getIndex(n, key);
if (a[index] == key) {

return index;
} else {
while (i != index) {
if (a[i] == key) {
return i;
break;
}
i = (i % n) + 1;
}
}
return -1;
}
void closedhashing() {
int n, a[10], key;
printf("Enter the size of the array:");
scanf("%d", &n);
for (i = 0; i < n; i++) {
a[i] = -1;
}
printf("\n-----MENU-----\n1)insert\n2)delete\n3)search\n4)display\n5)exit");
do {
printf("\nenter your choice:");
scanf("%d", &opt);
if (opt == 1) {
printf("\nEnter the element to insert:");
scanf("%d", &key);
close_insert(a, n, key);
printf("\n");
close_display(a, n);
} else if (opt == 2) {
printf("\nEnter the element to delete:");
scanf("%d", &key);
close_delete(a, n, key);
printf("\n");
close_display(a, n);
} else if (opt == 3) {
printf("\nEnter the element to search:");
scanf("%d", &key);
int elt = close_search(a, n, key);
if (elt != -1) {
printf("Element is found at the index%d", elt);
} else {

printf("Element is not found ");
}
} else if (opt == 4) {
printf("\n");
close_display(a, n);
printf("\n");
} else if (opt != 5) {
printf("Invalid operation!!");
}
} while (opt != 5);
}
int main() {
printf("\n1)Open Hashing\n2)closedHashing\nchoose your operation:");
scanf("%d", &opt);
if (opt == 1) {
openhashing();
} else {
closedhashing();
}
return 0;
}
