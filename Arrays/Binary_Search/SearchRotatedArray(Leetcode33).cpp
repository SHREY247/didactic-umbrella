/*There is an integer array nums sorted in ascending order (with distinct values).

Prior to being passed to your function, nums is possibly rotated at an unknown pivot index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ..., nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7] might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.*/

class Solution {
public:

    
//Function to find the maximum point of the array
int mainPoint(vector<int> arr,int n)
{     
	int l=0,h=n-1;
		while(l<=h)
		{
			int mid=(l+h)/2;
			//If last element is greater than middle one means maximum element would be lying in left part
			if(arr[mid]<=arr[n-1])
			{
				h=mid-1;
			}
			else
			{   
				//If you find a point ehre the next element is smaller than the current one, this is the maximum
				if(arr[mid]>arr[mid+1])
				{
					return mid;
				}
				
				//Otherwise maximum would lie in the right part
				else
					l=mid+1;
			}
		}
	//Return -1 for zero rotations case
	return -1;
}
 
int findTarget(vector<int> arr,int p,int n,int target)
{
	int l,h;
 		//If target is lesser than the last element, target lies to the right of main Point
		if(target<=arr[n-1])
		{
			l=p+1,h=n-1;
		}
	
	    //Otherwise, target lies in between indexes 0 and p (inclusive)
		else{
			l=0,h=p;
		}
	
	//Binary search
	while(l<=h)
	{
		int mid= (l+h)/2;
		if(arr[mid]==target)
		{
			return mid;
		}
		else if(arr[mid]>target)
		{
			h=mid-1;
		}
		else
		{
			l=mid+1;
		}
	}
	return -1;
}
 
        int search(vector<int>& nums, int target) {
        int n=nums.size();
        int p = mainPoint(nums,n);
	    int index = findTarget(nums,p,n,target);   
            
         if(index==-1){
					return -1;
				}
				
         else{
			return index;
		}             
    }
};
