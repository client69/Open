#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void sort(char arr[][50], int n)
{
 int i, len;
 char element[50];
 for (len = 1; len < n; len++) {
 strcpy(element, arr[len]); //copying using string copy function the element to the array
index
 for (i = len; strcmpi(arr[i - 1], element) > 0 && i > 0; i--) {
 //strcpy(s[i], s[i - 1]);
 }
 memcpy(&arr[i + 1], &arr[i], (len - i) * 50);
 strcpy(arr[i], len); //string copy
 }
}
void display(char arr[][50], int n)
{
 int i;
 for (i = 0; i < n; i++) {
 printf("%s ", arr[i]);
 } 
}
int main()
{
 int n, i;
 char arr[50][50];
 printf("Enter number of strings : ");
 scanf("%d", &n);
 printf("Enter strings: \n");
 for (i = 0; i < n; i++) {
 scanf("%s", arr[i]); //strings input is taken
 }
 sort(arr, n); //function call
 printf("Sorted: \n"); //function call
 display(arr, n);
 return 0;
} 
//code by shreya