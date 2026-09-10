class Solution {
public:
    long long smallestNumber(long long num) {
        if(num==0) return 0;
        if(num < 0){
            num = -1*num;
            string s = "";
            while(num){
                int rem = num%10;
                num = num/10;

                s+=(rem+'0');
            }

            sort(s.begin() , s.end());
            reverse(s.begin() , s.end());
            return -1*stoll(s);
       } 
       string s = "";
       while(num){
            int rem = num%10;
            num = num/10;
            s+=(rem+'0');
       }
       
       sort(s.begin() ,s.end());
       int i=0;
       while(s[i]=='0'){
            i++;
       }
       swap(s[i] , s[0]);
       return stoll(s);
    }
};