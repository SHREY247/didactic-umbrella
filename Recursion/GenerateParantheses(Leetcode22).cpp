//Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.

/*
Example:
Input: n = 3
Output: ["((()))","(()())","(())()","()(())","()()()"]

Code:
*/
class Solution {
public:

//ans initialized to store the final answer
vector<string> ans;

    //n represents pairs, l represents number of opening braces, r: closing braces and temp string to store result that we are computing
    void generate(int n,int l,int r, string temp){
        //Base case: If no. of opening braces equals no. of closing braces equals n  
        if(l+r==2*n){
            ans.push_back(temp);
            return;
        }

        //If opening braces equal closing braces bit not equal to n then we have just 1 option append opening brace
        if(l==r){
            temp+="(";
            generate(n,l+1,r,temp);
        }

        else if(l>r){
            //If l is greater than r but equals n then we need to append closing brace
            if(l==n){
                temp+=")";
                generate(n,l,r+1,temp);
            }

            else{
                temp+="(";
                generate(n,l+1,r,temp);

                temp.pop_back();

                temp+=")";
                generate(n,l,r+1,temp);
            }

        }
    }
    vector<string> generateParenthesis(int n) {
        generate(n,0,0,"");
        return ans;                
    }
};
