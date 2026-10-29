class Solution {
public:
    int rob(vector<int>& nums) {
        int prevRob = 0;
        int maxRob = 0;

        for (int earn: nums) {
            int temp = max(maxRob, prevRob + earn);
            prevRob = maxRob;
            maxRob = temp;
        }

        return maxRob;        
    }
};