class Solution {
public:
    string largestNumber(vector<int>& nums) {
        auto mycomparator = [](int& a , int& b){
            string str1 = to_string(a);
            string str2 = to_string(b);

            return str1+str2 > str2+str1;
        };      

        sort(nums.begin() , nums.end() , mycomparator);

        if(nums[0]==0) return "0";

        string s="";
        for(int i=0 ; i<nums.size() ; i++){
            s+=to_string(nums[i]);
        }
        return s;
    }
};