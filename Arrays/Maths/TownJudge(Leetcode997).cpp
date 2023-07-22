/*In a town, there are n people labeled from 1 to n. There is a rumor that one of these people is secretly the town judge.
If the town judge exists, then:
The town judge trusts nobody.
Everybody (except for the town judge) trusts the town judge.
There is exactly one person that satisfies properties 1 and 2.
You are given an array trust where trust[i] = [ai, bi] representing that the person labeled ai trusts the person labeled bi.
Return the label of the town judge if the town judge exists and can be identified, or return -1 otherwise.*/

class Solution {
public:
    int findJudge(int n, vector<vector<int>> trust) {
       vector<pair<int,int>>v(n+1,{0,0});  /*1st element represents how many people that particular person trusts and 2nd element represents how many people trust him*/
       for(int i=0;i<trust.size();i++){
           v[trust[i][0]].first+=1;
            v[trust[i][1]].second+=1;

       }

       for(int i=1;i<=n;i++){
           if(v[i].first==0 && v[i].second==n-1){
               return i;
           }
          
}
    return -1;
    }      
};
       
