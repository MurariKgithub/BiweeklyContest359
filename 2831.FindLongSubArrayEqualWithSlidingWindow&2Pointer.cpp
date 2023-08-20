class Solution{
public:
    
    int longestEqualSubarray(vector<int>& nums, int k) {
        // if(k==0)   return 1;
        int n = nums.size(),MaxOcc = 0,DomNum=0,left=0,del=0,result=1;
        // vector<vector<int>> mp(n+1);
        unordered_map<int,int> frq;
//         
        for(int right=0 ;right<n ;right++){
            result = max(result,++frq[nums[right]]);
            if(right-left-result+1>k)  frq[nums[left++]]--;
        }
        return result;
    }
};
