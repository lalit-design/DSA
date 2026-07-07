class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1;
        int high=*max_element(nums.begin(), nums.end());
        int n=nums.size();
        int result=-1;
        while(low<=high){
            int mid=low+(high-low)/2;
            int count=0;
            for(int i=0;i<=n-1;i++){
                count=count+((nums[i]+mid-1)/mid);
            }
            if(count<=threshold){
                result=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }
        }return result;
    }
};