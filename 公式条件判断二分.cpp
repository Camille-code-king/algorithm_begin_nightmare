using namespace std;
#include<iostream>
#include<numeric>
#include<algorithm>
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        auto check=[&](int mid)->bool{
            int sum=piles.size();
            for(int p:piles){
                sum+=(p-1)/mid;
                if(sum>h)return false;
            }
            return true;
        };
        int l=1;
        int r=*max_element(piles.begin(),piles.end());
        while(l<=r){
            int mid=l+(r-l)/2;
            check(mid)?r=mid-1:l=mid+1;
        }
        return l;
    }
};
