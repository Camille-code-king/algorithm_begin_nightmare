class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> heights(col, 0); 
        int ans = 0;
        for (int i = 0; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                if (matrix[i][j] == '1') {
                    heights[j]++;
                } else {
                    heights[j] = 0;
                }
            }
            stack<int> st;
            vector<int> left(col, -1);
            vector<int> right(col, col);
            for (int j = 0; j < col; ++j) {
                while (!st.empty() && heights[st.top()] > heights[j]) {
                    right[st.top()] = j;
                    st.pop();
                }
                st.push(j);
            }
            st=stack<int>();
            for (int j = col - 1; j >= 0; --j) {
                while (!st.empty() && heights[st.top()] > heights[j]) {
                    left[st.top()] = j;
                    st.pop();
                }
                st.push(j);
            }
            for (int j = 0; j < col; ++j) {
                int width = right[j] - left[j] - 1;
                ans = max(ans, width * heights[j]);
            }
        }
        return ans;
    }
};
