class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int ans=0;
        int low=1;
        int high=*max_element(piles.begin(),piles.end());
        int n=piles.size();
        while(low<=high){
            int mid=low+(high-low)/2;
          long long int count=0;
            for(int i=0;i<=n-1;i++){
                int div=piles[i]/mid;
                if(div==0){
                    count++;
                }
                else{
                    if((piles[i]%mid)!=0){
                        count=count+div+1;
                    }
                    else{
                        count=count+div;
                    }
                }

            }
            if(count<=h){
               ans=mid;
               high=mid-1;
            
            }else{
                low=mid+1;
                
            }
        }return ans;
    }
};