// Counting sort: This is non - comparison based sorting algorithm, where we would be storing the cumulative frequency
//of each element and then iterate over our actual array and place the elements at its deserving location and then update the cumulative frequencies

//Time complexity: max(O(N), 0(max-min))

#include <bits/stdc++.h>
#include <string.h>
using namespace std;
#define RANGE 255             //The range of characters 


void countSort(char arr[])
{
    // The output character array that will be sorted
    char output[strlen(arr)];

    // Create a count array to store count of individual characters and initialize count array as 0
    int count[RANGE + 1], i;
    memset(count, 0, sizeof(count));

    // Store count of each character
    for (i = 0; arr[i]; ++i)
        ++count[arr[i]];

    // Change count[i] so that count[i] now contains actual slot of this character in output array
    for (i = 1; i <= RANGE; ++i)
        count[i] += count[i - 1];

    // Build the output character array, The index in output array would be count[arr[i]]-1 
    for (i = 0; arr[i]; ++i) {
        output[count[arr[i]] - 1] = arr[i];
        --count[arr[i]];
    }

    /* The above code doesn't ensure stability, so in case of stability, start from the end instead of starting from index 0
    For Stable algorithm
    for (i = sizeof(arr)-1; i>=0; --i)
    {
        output[count[arr[i]]-1] = arr[i];
        --count[arr[i]];
    }  
    */

    // Copy the output array to arr, so that arr now contains sorted characters
    for (i = 0; arr[i]; ++i)
        arr[i] = output[i];
}

// Driver code
int main()
{
    char arr[] = "shrey";

    // Function call
    countSort(arr);

    cout << "Sorted character array is " << arr;
    return 0;
}
