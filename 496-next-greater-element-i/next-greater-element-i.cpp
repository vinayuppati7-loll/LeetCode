class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1= nums1.size();
        int n2 = nums2.size();
        vector<int> answer(n1,-1);
        stack<int> st;
        unordered_map<int,int> nge;

        for(int i = 0;i<n2;i++){
                while(!st.empty() && nums2[st.top()] < nums2[i]){
                    nge[nums2[st.top()]] = nums2[i];
                    st.pop();
                }
                st.push(i);
            }
        //to find answers for nums1
        for(int i =0;i<n1;i++){
            if(nge.find(nums1[i]) != nge.end()){//it's like checking whther i is in the map or not
                answer[i] = nge[nums1[i]];
            }
        }
        return answer;
    }
};