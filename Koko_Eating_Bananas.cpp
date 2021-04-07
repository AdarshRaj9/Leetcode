class Solution {
public:
    bool check(vector<int>arr,int mid,int h)
    {
        int hr=0;
        for(auto pile:arr)
        {
            hr+=pile/mid;
            if(pile%mid)
            {
                hr++;
            }
        }
        return hr<=h;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1,high=*max_element(piles.begin(),piles.end());
        while(low<=high)
        {
            int mid=(low+high)/2;
            if(check(piles,mid,h))
            {
                high=mid-1;
            }
            else
            {
                low=mid+1;
            }
        }
        return low;
    }
};