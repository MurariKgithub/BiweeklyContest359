class Solution{
public:
    
    int longestEqualSubarray(vector<int>& nums, int k) {
        // if(k==0)   return 1;
        int n = nums.size(),MaxOcc = 0,DomNum=0,l=0,del=0,result=1;
        vector<vector<int>> mp(n+1);
        unordered_map<int,int> frq;
        for(int i=0 ;i<n ;i++){
            mp[nums[i]].push_back(i);
        }
        for(auto array:mp){
            if(array.empty()) continue;
            vector<int> arr = array;
            int m = arr.size();
            int l =0,r =1;
            while(l<m){
                while(r<m and (arr[r]-arr[l])-(r-l)<=k)  r++;
                
                result = max(result,r-l);
                l++;
            }
        }
        return result;
    }
};
