// To find out whether two values present in an array of size n add up to a value k
#include <iostream>
using namespace std;
int main() {
    // Write C++ code here
    
    int n,k,a=0,z;
    cout<<"Enter the length of the array\n";
    cin>>n;  //length of array
    int arr[n];
    cout<<"Enter "<<n<<" Values\n";
    for(int b=0;b<n;b++)
    {
        cin>>arr[b];
    }
    cout<<"Enter value of k\n";
    cin>>k;
    
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
        	
 			 if((i!=j) && (arr[i]+arr[j]==k))
            {
                a=1;
                
            }
        }
        
    }
    if(a==1)
    {
	
    cout<<"True";
}
    else{
	
    cout<<"False";
}
    
    
    return 0;
}
