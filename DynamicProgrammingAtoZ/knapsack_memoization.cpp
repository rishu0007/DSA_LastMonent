#include<bits/stdc++.h>
using namespace std;

const int d = 1001;
int dp[d][d];

int knapsack(int W, int wt[], int val[], int n) {
    // base case 
    if(W == 0 || n == 0) return 0;

    if(dp[n][W] != -1) return dp[n][W];

    if(wt[n-1] <= W) {
        return dp[n][W] = max((val[n-1] + knapsack(W-wt[n-1],wt,val,n-1)), knapsack(W,wt,val,n-1));
    }
    return knapsack(W,wt,val,n-1); // if wt[n - 1] > W
}

int main() {
    int n;
    cin >> n;
    int val[n], wt[n];

    for(int i = 0; i < n; i++) {
        cin >> val[i];
    }
    for(int i = 0; i < n; i++) {
        cin >> wt[i];
    }

    int W;
    cin >> W;

    cout << "Answer is " << knapsack(W,wt,val,n);

    return 0;
}
