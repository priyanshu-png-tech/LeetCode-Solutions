class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        deque<int>deq;
        int ans = INT_MAX;
        int sum = 0;
        vector<int>cumsum;
        

        for(int i=0 ; i<nums.size() ;i++){
            sum+=nums[i];

            if(sum>=k){
                ans = min(ans , i+1);
            }

            while(!deq.empty() && sum - cumsum[deq.front()]>=k){
                ans = min(ans , i-deq.front());
                deq.pop_front();
            }

            while(!deq.empty() && cumsum[deq.back()] > sum){
                deq.pop_back();
            }

            deq.push_back(i);
            cumsum.push_back(sum);
        }

        return ans==INT_MAX ? -1 : ans;
    }
};