//To calculate average of numbers using arrays and to display largest element of an array. To add two matrix using multi-dimensional array

#include <stdio.h>

void avgAndLargest(int arr[], int n) {
    int sum = 0;
    for(int i=0; i<n; i++) {
        sum += arr[i];
    }
    float avg = sum/n;
    int largest = arr[0];
    for(int i=1; i<n; i++) {
        if(arr[i] > largest) {
            largest = arr[i];
        }
    }
    printf("Average is %f\n", avg);
    printf("Largest Number is %d\n", largest);
}

void sum(int row, int col, int arr1[][row], int arr2[][row]) {
    int sum[col][row];
    for(int i=0; i<col; i++) {
        for(int j=0; j<row; j++) {
            sum[i][j] = arr1[i][j] + arr2[i][j];
        }
    }
    for(int i=0; i<col; i++) {
        for(int j=0; j<row; j++) {
            printf("%d\t", sum[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int arr[] = {4,2,4,6,8,7,6,3,5};
    int arr1[][3] = {{1,2,3}, {4,5,6}, {7,8,9}, {10,11,12}};
    int arr2[][3] = {{12,11,10}, {9,8,7}, {6,5,4}, {3,2,1}};
    avgAndLargest(arr, 9);
    sum(4, 3, arr1, arr2);
}