class Solution {
public:

    bool isvalid(vector<int>& nums, int n,int k,int mid){
        int sum1 = 0;
        int student = 1;
        for(int i =0;i<n;i++){
            sum1 = sum1 + nums[i];
            if(sum1>mid){
                student++;
                sum1 = nums[i];
            }
            if(student>k){
                return false;
            }
        }return true;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int low = *max_element(nums.begin(),nums.end());
        if(n<k){
            return -1;
        }
        // for finding high
        int sum = 0;
        for(int i = 0;i<n;i++){
            sum = sum + nums[i];
        }
        int high = sum;
        int ans = -1;
        while(low<=high){
            int mid = low + (high-low)/2;
            
            //to check function
            if( isvalid(nums,n,k,mid)==true){
                ans = mid;
                high = mid -1;
            }else{
                low = mid + 1;
            }
        }
        return ans;
    }
};