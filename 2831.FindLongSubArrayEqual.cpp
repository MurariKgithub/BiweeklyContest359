class Solution{
public:
    int BinarySearch(vector<int>& a,int s,int k){
        int n = a.size() ,l=s ,h = n-1;
        while(l<=h){
            int mid = l+(h-l)/2;
            if((a[mid]-a[s]+1)-(mid-s+1)<=k) l = mid+1;
            else h = mid-1;
        }
        return h-s+1;
    }
    int longestEqualSubarray(vector<int>& nums, int k) {
        // if(k==0)   return 1;
        int n = nums.size(),MaxOcc = 0,DomNum=0,l=0,del=0,curmax=0;
        vector<vector<int>> mp(n+1);
        unordered_map<int,int> frq;
        for(int i=0 ;i<n ;i++){
            mp[nums[i]].push_back(i);
        }
        for(auto array:mp){
            // if(array.empty()) continue;
            vector<int> a = array;
            int m = a.size();
            for(int left = 0;left<m ;left++){
                int idx = BinarySearch(a,left,k);
                curmax = max(curmax,idx);
            }
                // cout<<idx<<endl;
                // idx+=frq[nums[i]]==idx?0:1;
                // cout<<idx<<" "<<nums[i]<<"<-"<<i<<endl;
            
             
            // frq[nums[i]]++;
        }
        return curmax;
    }
};
