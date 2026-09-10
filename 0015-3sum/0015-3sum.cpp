class Solution {
public:
    vector<vector<int>>result;
    void twoSum(vector<int>& nums , int i , int j , int target){
        while(i<j){
            int sum = nums[i]+nums[j];
            if(sum<target){
                i++;
            }
            else if(sum>target){
                j--;
            }
            else{
                while(i<j && nums[i]==nums[i+1]) i++;
                while(j>i && nums[j]==nums[j-1]) j--;

                result.push_back({-target , nums[i] , nums[j]});
                i++ , j--;
            }
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        if(nums.size()==0){
            return {};
        }      

        sort(nums.begin() , nums.end());
        int n= nums.size();
        for(int i=0 ; i<n ; i++){
            if(i>0 && nums[i]==nums[i-1]){
                continue;
            }
            int target = -(nums[i]);
            twoSum(nums , i+1 , n-1 , target);
        }
        return result;
    }
};