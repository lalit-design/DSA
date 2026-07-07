class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        int low = *min_element(bloomDay.begin(), bloomDay.end());
;
        int high = *max_element(bloomDay.begin(), bloomDay.end());
        int res=-1;
        while(low<=high){
            int count=0;
            int ans=0;
            int mid=low+(high-low)/2;
            
            for(int i=0;i<=n-1;i++){
                //to count the number of blooming days
                if(bloomDay[i]<=mid){
                    count=count+1;
                }else{
                    count=0;
                }
            //reset the count and update ans
            if(count==k){
                count=0;
                ans=ans+1;
            }
         }
        //check for ans and updating low and high
            if(ans>=m){
                res=mid;
                high=mid-1;
            }else{
                low=mid+1;
            }

            

            
        }return res;
    }
};