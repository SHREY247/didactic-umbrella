//Find the minimum number of swaps required to bring all the numbers less than or equal to k together
#include <bits/stdc++.h>


using namespace std;

int main() {

  

    int n,k;
	cout<<"Enter size of array and k respextively\n";
    cin>>n>>k;

    int arr[n];
	cout<<"Enter "<<n<<" elements\n";
    for(int i=0;i<n;i++)

    {

        cin>>arr[i];

    }

    int legalElement=0;

    for(int i=0;i<n;i++)

    {

        if(arr[i]<=k)

        {

            legalElement++;

        }

    }

    

    int cnt=0;

    for(int j=0;j<legalElement;j++)

    {

       if(arr[j]<=k)

       {

          cnt++; 

       }

    }

    int maxm=cnt;

    for(int m=legalElement;m<n;m++)

    {

       maxm=max(maxm,cnt);
		//If removed element is less than k count will be reduced by 1
		if(arr[m-legalElement]<=k)

       {

           cnt--;

       }
		//if new element  is greater than k then count is increased by 1
       if(arr[m]<=k)

       {

           cnt++;

       }

       

    }



     int final=legalElement-maxm;
	cout<<"Minimum number of swaps needed so that elements less than "<<k<<" come together is "<<final<<endl;
 

    return 0;

}
