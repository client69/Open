#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

//This function does binary search recursively. If the number is not in the array, it returns -1. If it is, it returns the position the number is in.
int binaryFunc(int *arrayNum, int firstPosition, int lastPosition, long long int chosenNum) {
    int32_t p = (firstPosition + lastPosition) / 2;
    if(lastPosition < firstPosition){
        return -1;
    }else if(arrayNum[p] == chosenNum){
        return p;
    }else if(arrayNum[p] < chosenNum){
        return binaryFunc(arrayNum, p + 1, lastPosition, chosenNum);
    }else{
        return binaryFunc(arrayNum, firstPosition, p - 1, chosenNum);
    }
}

//This code does binary search to find the given number in a given sorted array.
int main (){
    int chosenNumber,position;
    int firstPostionArray=0, lastPostionArray=9;
    int arrayNumbers[10] = {1, 20, 23, 67, 89, 91, 101, 300, 323, 1001};
    chosenNumber=20;
    position=binaryFunc(arrayNumbers,firstPostionArray,lastPostionArray,chosenNumber);
    if(position!=-1){
        printf("The number you are searching for is in this array! It is in the position number %d.\n",position);
    }else{
        printf("The number you are searching for is not in this array.\n");
    }
}
