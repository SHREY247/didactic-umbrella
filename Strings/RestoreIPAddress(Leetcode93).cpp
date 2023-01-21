/*A valid IP address consists of exactly four integers separated by single dots. Each integer is between 0 and 255 (inclusive) and cannot have leading zeros.
For example, "0.1.2.201" and "192.168.1.1" are valid IP addresses, but "0.011.255.245", "192.168.1.312" and "192.168@1.1" are invalid IP addresses.
Given a string s containing only digits, return all possible valid IP addresses that can be formed by inserting dots into s.
You are not allowed to reorder or remove any digits in s. You may return the valid IP addresses in any order.*/

class Solution {
public:
    //To check whether particular segment is valid or not
    bool check(string s){
        int n=s.size();
        if(n==1){
            return true;  //size of string 1 is always valid so return true
        }

        if(n>3||s[0]=='0'){
            return false; //if size>3 or starts with 0 then invalid 
        }

        int value = stoi(s); //Converting string to integer
        if(value>255){
            return false;
        }
        return true;
    }
    vector<string> restoreIpAddresses(string s) {
        int n=s.size();
        vector<string> ans;
        if(n>12){
            return ans;    /*Max length of ans could be (3*4)=12 so all strings of length greater than 12 can have answer*/
        }        
        /*2 options left:
        1: n=12
        2:n<12

        Split s in such a way that it is valid ip 
        If all the 4 strings pass the check, push into ans 
        */

          for(int i=1;i<=3;i++){//for Segment 1
            for(int j=1;j<=3;j++){//for Segment 2
                for(int k=1;k<=3;k++){//for Segment 3
                    //checking condition if the last segment is of length 3 or less
                    if(i+j+k<n&&i+j+k+3>=n){
                        //dividing the s int substrings 
                        string a=s.substr(0,i);
                        string b=s.substr(i,j);
                        string c=s.substr(j+i,k);
                        string d=s.substr(i+j+k);

                        /*if all the substring satisfy the check function condition 
                        then we will push into ans vector */
                          if(check(a)&&check(b)&&check(c)&&check(d)){
                            ans.push_back(a+"."+b+"."+c+"."+d);
                        }
                    }
                }

            }
          }
          return ans;
    }
};

 
