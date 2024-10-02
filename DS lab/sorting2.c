#include<stdio.h>
#define MAX 15
int i, pivot;
void display(int a[], int n) {
for(i = 0; i < n; i++) {
printf("%d ", a[i]);
}
}
void read(int a[], int n) {
printf("Enter the elements:\n");
for(i = 0; i < n; i++) {
scanf("%d", &a[i]);
}
}
void swap(int a[], int index1, int index2) {
int temp = a[index1];
a[index1] = a[index2];
a[index2] = temp;
}
void quicksort(int a[], int startIndex, int endIndex)
{
if(startIndex >= endIndex) {
return;
}
pivot = a[startIndex];
int leftPointer = startIndex;
int rightPointer = endIndex;
while(leftPointer < rightPointer) {
while(a[leftPointer] <= pivot && leftPointer <=
rightPointer) {
leftPointer++;
}
while(a[rightPointer] > pivot && leftPointer <=
rightPointer) {
rightPointer--;
}
if(leftPointer < rightPointer) {
swap(a, rightPointer, leftPointer);
}
}
swap(a, rightPointer, startIndex);
quicksort(a, startIndex, rightPointer - 1);
quicksort(a, rightPointer + 1, endIndex);
}

void merge(int arr[], int arrlen, int left[], int leftlen,
int right[], int rightlen) {
int i = 0, j = 0, k = 0;

while(i < leftlen && j < rightlen) {
if(left[i] <= right[j]) {
arr[k] = left[i];
i++;
} else {
arr[k] = right[j];
j++;
}
k++;
}
while(i < leftlen) {
arr[k] = left[i];
i++;
k++;
}
while(j < rightlen) {
arr[k] = right[j];
j++;
k++;
}
}
void mergeSort(int arr[], int n) {
int mid, leftSubArray[MAX], rightSubArray[MAX],
j, i;
if(n < 2) {
return;
}
mid = n / 2;
for(i = 0; i < mid; i++) {
leftSubArray[i] = arr[i];
}
for(i = mid, j = 0; i < n; i++, j++) {
rightSubArray[j] = arr[i];
}
mergeSort(leftSubArray, mid);
mergeSort(rightSubArray, n - mid);
merge(arr, n, leftSubArray, mid, rightSubArray, n
- mid);
}
void minheapify(int a[], int n, int i) {
int min = i;
int left = 2 * i + 1;
int right = 2 * i + 2;
if(left < n && a[left] < a[min]) {
min = left;
}
if(right < n && a[right] < a[min]) {
min = right;
}
if(min != i) {

int temp = a[i];
a[i] = a[min];
a[min] = temp;
minheapify(a, n, min);
}
}
void minheapsort(int a[], int n) {
for(i = n / 2 - 1; i >= 0; i--) {
minheapify(a, n, i);
}
for(i = n - 1; i > 0; i--) {
int temp = a[0];
a[0] = a[i];
a[i] = temp;
minheapify(a, i, 0);
}
}
void maxheapify(int a[], int n, int i) {
int max = i;
int left = 2 * i + 1;
int right = 2 * i + 2;
if(left < n && a[left] > a[max]) {
max = left;
}
if(right < n && a[right] > a[max]) {
max = right;
}
if(max != i) {
int temp = a[i];
a[i] = a[max];
a[max] = temp;
maxheapify(a, n, max);
}
}
void maxheapsort(int a[], int n) {
for(i = n / 2 - 1; i >= 0; i--) {
maxheapify(a, n, i);
}
for(i = n - 1; i > 0; i--) {
int temp = a[0];
a[0] = a[i];
a[i] = temp;
maxheapify(a, i, 0);
}
}

int main() {
int n, a[15], opt;
printf("\n------MENU------\n1)Quicksort\n2)Merge sort\n3)Heapsort\n4)Display\n5)exit");
do {
printf("\nChoose your operation:");
scanf("%d", &opt);
if(opt == 1) {
printf("Enter the size of the array:");
scanf("%d", &n);
read(a, n);
printf("\nBEFORE:\n");
display(a, n);
quicksort(a, 0, n - 1);
printf("\nAFTER:\n");
display(a, n);
printf("\n");
} else if(opt == 2) {
printf("Enter the size of the array:");
scanf("%d", &n);
read(a, n);
printf("\nBEFORE:\n");
display(a, n);
mergeSort(a, n);
printf("\nAFTER:\n");
display(a, n);
printf("\n");
} else if(opt == 3) {
printf("Enter the size of the array:");
scanf("%d", &n);
read(a, n);
printf("\nBEFORE:\n");
display(a, n);
printf("\n1)max-heap\n2)min-heap\nchoose:");
scanf("%d", &opt);
if(opt == 1) {
maxheapsort(a, n);
} else {
minheapsort(a, n);
}
printf("\nAFTER:\n");
display(a, n);
printf("\n");
} else if(opt == 4) {
display(a, n);
printf("\n");
} else if(opt != 5) {
printf("Invalid operation!!");
}
} while(opt != 5);
return 0;
}
