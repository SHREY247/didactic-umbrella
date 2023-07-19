/*The task is to complete the insert() function which is used to implement Insertion Sort.*/

class Solution
{
    public:
    void insert(int arr[], int i)
    {
        //code here
       while(i>0 && arr[i]<arr[i-1]){
           int temp=arr[i];
           arr[i]=arr[i-1];
           arr[i-1]=temp;
           i--;
       }
    }
     public:
    //Function to sort the array using insertion sort algorithm.
    void insertionSort(int arr[], int n)
    {
        //code here
        for (int i = 1; i < n; i++) {
                insert(arr, i);
            }
    }
};

