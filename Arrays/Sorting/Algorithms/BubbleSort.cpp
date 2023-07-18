/*
Given an Integer N and a list arr. Sort the array using bubble sort algorithm.
Example 1:

Input: 
N = 5
arr[] = {4, 1, 3, 9, 7}
Output: 
1 3 4 7 9

Expected Time Complexity: O(N^2).
Expected Auxiliary Space: O(1).
*/

class Solution
{
    public:
    //Function to sort the array using bubble sort algorithm.
   void bubbleSort(int arr[], int n)
{
    //Initialize a variable named done to 0 to signify that sorting is not done 
    int done = 0;
    
    int i;
    //Run a while loop until sorting is done, i.e., done becomes true
    while(!done){
        //Mark done as 1
        done=1;
        
        i=0;
        while(i<n-1){
            //If you find that array is still unsorted
            if(arr[i]>arr[i+1]){
                //swap
                int temp=arr[i+1];
                arr[i+1]=arr[i];
                arr[i]=temp;
              
                //Mark done as false 
                done = 0;
            }
            i++;
        }
        
    }
    
    
}
};
