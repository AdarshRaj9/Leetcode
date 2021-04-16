class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n=nums.size();
        if(n<=1)
            return nums[0];
        int p1=0,p2=1;
        int sum=nums[0],mx_sum=nums[0];
        while(p2<n and p1<p2)
        {
            if(nums[p2]>nums[p2-1])
            {
                sum+=nums[p2];
                mx_sum=max(mx_sum,sum);
                //cout<<sum<<" "<<mx_sum<<",";
                p2++;
            }
            else
            {
                sum=nums[p2];
                p1=p2;
                p2++;
                //sum=0;
            }
        }
        return mx_sum;
        
    }
};