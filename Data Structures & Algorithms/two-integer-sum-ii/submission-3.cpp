class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l =0, r = numbers.size() - 1;

        while (l<r){
            int Sum  = numbers[l] + numbers[r] ; 
            if (Sum == target){
                return {l+1, r+1};}
                else if (Sum < target ){
                    l++;}
                    else if (Sum > target){
                        r--;
                    }
                
            
    
        }
        return {};
    }
};
