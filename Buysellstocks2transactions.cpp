/*You are given an array prices where prices[i] is the price of a given stock on the ith day.
 Find the maximum profit you can achieve. 
 You may complete at most two transactions.*/
 
 #include <iostream>
#include <vector>
using namespace std;
 int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n==1)return 0;
        int pmin[n],smax[n],maxprofit=0,profit,preprofit=0,postprofit=0,i;
        pmin[0]=prices[0];
        smax[n-1]=prices[n-1];
        for(i=1;i<n;i++){
            pmin[i]=min(pmin[i-1],prices[i]);
        }

        for(i=n-2;i>=0;i--){
            smax[i]=max(smax[i+1],prices[i]);
        }

        for(i=1;i<n-1;i++){
            profit=0;postprofit=0;       
            preprofit=max(preprofit,prices[i]-pmin[i-1]);			
            if((i+2)!=n && smax[i+2]-prices[i+1]>0)
                postprofit=(smax[i+2]-prices[i+1]);		
            profit=preprofit+postprofit;
			maxprofit=max(maxprofit,profit);
        }
        profit=prices[n-1]-pmin[n-2];
        if(profit>0)
            maxprofit=max(maxprofit,profit);
        if(n==3){
            profit=smax[1]-pmin[1];
            maxprofit=max(profit,maxprofit);
        }
        return maxprofit;       
    }
int main() {
    // your code goes here
    int n,i,a;
    cout<<"Enter n\n";
	cin>>n;
    vector<int>nums ;  
	cout<<"Enter "<<n<<" elements\n";                                                    
    for(i=0;i<n;i++)
    {
        cin>>a;
        nums.push_back(a);
    }
    cout<<"Maximum profit is ";
    cout<<maxProfit(nums);
    return 0;

}
