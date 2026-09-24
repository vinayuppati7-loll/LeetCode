class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> answer(n,-1);
        stack<int> st;
        // (i%n) is playing with imaginary indices 
        //we imagine the array to be written to written 2 times continuosly and 
        //giving the index value contuinosly!
        for(int i = 2*n-1;i>=0;i--){//back traversing
            while(!st.empty() && st.top() <= nums[i%n]){
                st.pop();
            }
            if(i<n && !st.empty()){
                answer[i%n] =st.top();
            }
            st.push(nums[i%n]);
        }
    
    return answer;

    }
};