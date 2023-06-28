//You are given an array A of N numbers, output the count of pairs in the array whose sum is divisible by 4 .

#include <iostream>
using namespace std;
int main() {
int t;
cin >> t;
while(t--){
int n,ans=0;
cin >> n;
int arr[n];
for(int i = 0; i < n; i++){
cin >> arr[i];
}

int cnt[4];
for(int i = 0; i < 4; i++){
cnt[i]=0;
}

for(int i = 0; i < n; i++){
cnt[arr[i]%4]++;
}
//r1+r2 must be equal to 0 or 4

//Case where r1 + r2 == 0
//Both elements will be picked from the 0th basket
//For that, we would be having N_C_2 choices
//Formula for N_C_2 used below	
ans = ans + (cnt[0]*(cnt[0]-1))/2;

//Case when r1+r2==k 	
for(int i = 1; i <= (4/2)-1; i++){
ans = ans + cnt[i] * cnt[4-i];
}

//Since 4 is even, therefore, we'll have to pick 2 elements from the middle bucket
//For that, we would be having N_C_2 choices
//Formula for N_C_2 used below
ans = ans + (cnt[2]*(cnt[2]-1))/2;
cout << ans << endl;
}

    return 0;

}
