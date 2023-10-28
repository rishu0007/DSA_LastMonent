// Leetcode 42 Trapping ranin water

#include<iostream>
#include<vector>
using namespace std;

vector<int> maiximumAtLeft(vector<int>& height) {
    int n = height.size();
    vector<int> maxL(n);
    maxL[0] = height[0];
    for(int i = 1; i < height.size(); i++) {
        maxL[i] = max(maxL[i-1], height[i]);
    }
    return maxL;
}

vector<int> maximumAtRight(vector<int>& height) {
    int n = height.size();
    vector<int> maxR(n);
    maxR[n-1] = height[n-1];
    for(int i = n-2; i >= 0; i--) {
        maxR[i] = max(maxR[i+1],height[i]);
    }
    return maxR;
}

int main() {

    vector<int> height = {0,1,0,2,1,0,1,3,2,1,2,1};
    int ans = 0;
    int n = height.size();
    vector<int> water(n);
    vector<int> maxL = maiximumAtLeft(height);
    vector<int> maxR = maximumAtRight(height);
    for(int i = 0; i < n; i++) {
        water[i] = min(maxL[i], maxR[i]) - height[i];
        ans += water[i];
    }

    cout << "The trapped water after raining is : " << ans;

    return 0;
}