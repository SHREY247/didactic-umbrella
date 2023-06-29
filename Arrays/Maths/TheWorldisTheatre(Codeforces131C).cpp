/*There are n boys and m girls attending a theatre club. To set a play "The Big Bang Theory", they need to choose a group
containing exactly t actors containing no less than 4 boys and no less than one girl.
  How many ways are there to choose a group? Of course, the variants that only differ
in the composition of the troupe are considered different.*/

#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
#define int long long
const int MOD = 1e9 + 7;
const int INF = LLONG_MAX >> 1;
signed main()
{
    int pas[61][61];
    pas[0][0] = 1;
    for (int i = 1; i <= 60; i++)
    {
       for (int j = 0; j <= i; j++)
        {
		   //nC0 = nCn = 1
            if (j == 0 || j == i)
            {
                pas[i][j] = 1;
            }

            else
            {  
				//nCr = n-1Cr + n-1Cr-1
               pas[i][j] = pas[i - 1][j] + pas[i - 1][j - 1];
            }
        }
    }
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, x;
        cin >> n >> m >> x;
        int ans = 0;
		//i represents boys
		//j represents girls
		//Start the loop for boys from 4 as we require a minimum of 4 boys
        for (int i = 4; i <= n; i++)
        {   
			//If j is between 1 and m, then only add to answer
            int j = x - i;
            if (j >= 1 && j <= m)
                ans += pas[n][i] * pas[m][j];
        }

       cout << ans << endl;

    }



    return 0;

}
