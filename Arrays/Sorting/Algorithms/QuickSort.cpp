/*
Quick Sort is a Divide and Conquer algorithm. It picks an element as a pivot and partitions the given array around the picked pivot.
Given an array arr[], its starting position is low (the index of the array) and its ending position is high(the index of the array).

Note: The low and high are inclusive.

Implement the partition() and quickSort() functions to sort the array.*/


//{ Driver Code Starts
#include <stdio.h>
#include <bits/stdc++.h>
using namespace std;

/* Function to print an array */
void printArray(int arr[], int size)
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

// } Driver Code Ends

class Solution
{
    public:
    //Function to sort an array using quick sort algorithm.
    void quickSort(int arr[], int low, int high)
    {
 
     if(low<high){
         int pivot=partition(arr,low,high);
         quickSort(arr,low,pivot-1);
         quickSort(arr,pivot+1,high);
     }   
    }
 
    public:
    int partition (int arr[], int low, int high)
    {   
       //Pivot is at arr[low]
       int l=low+1,r=high;
       //Run the loop till low becomes >=high
       while(l<=r){
           //Keep on incrementing l uptil you find an element>pivot
           //This is because we want all the elements smaller than equal to pivot towards its left
           while(arr[l]<=arr[low] && l<=high) l++;
           
           //Similarly, keep on decrementing r uptil you find an element<=pivot
           while(r>=low && arr[r]>arr[low]) r--;
           
           //If l is less than r, swap arr [i] and arr[j]
           //This will ensure that smaller elements than pivot remain to the left of it and larger ones on its right by swapping the smaller and larger elements
           if(l<r)  swap(arr[l],arr[r]);
        
       }
       
       //In the end, place pivot at its correct position
       //The correct position is determined by arr[j] when the outer while loop breaks
       swap(arr[low],arr[r]);
       //return the index of pivot
       return r;
    }
};


//{ Driver Code Starts.
int main()
{
    int arr[1000],n,T,i;
    scanf("%d",&T);
    while(T--){
    scanf("%d",&n);
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
      Solution ob;
    ob.quickSort(arr, 0, n-1);
    printArray(arr, n);
    }
    return 0;
}
// } Driver Code Ends
