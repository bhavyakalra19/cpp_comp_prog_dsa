// https://www.naukri.com/code360/problems/ninja%E2%80%99s-training_3621003?utm_source=striver&utm_medium=website&utm_campaign=a_zcoursetuf&leftPanelTabValue=SUBMISSION

int getAns(vector<vector<int>> &points, int idx, int n, int last, vector<vector<int>> &dp){
    if(dp[idx][last] != -1){
        return dp[idx][last];
    }
    if(idx == 0){
        int mx = 0;
        for(int i = 0; i < 3; i++){
            if(i != last){
                mx = max(mx, points[0][i]);
            }
        }
        return dp[idx][last] = mx;
    }
    int mx = 0;
    for(int i = 0; i < 3; i++){
        if(last != i){
            mx = max(mx,points[idx][i] + getAns(points, idx - 1, n, i, dp));
        }
    }
    return dp[idx][last] = mx;
}


int ninjaTraining(int n, vector<vector<int>> &points){
    // Write your code here.
    vector<vector<int>> dp(n,vector<int>(4,-1));
    dp[0][0] = max(points[0][1],points[0][2]);
    dp[0][1] = max(points[0][0],points[0][2]);
    dp[0][2] = max(points[0][0],points[0][1]);
    dp[0][3] = max(points[0][0], max(points[0][1],points[0][2]));

    for(int i = 1; i < n; i++){
        for(int last = 0; last < 4; last++){
            int mx = 0;
            for(int task = 0; task < 3; task++){
                if(last != task){
                    mx = max(mx, points[i][task] + dp[i-1][task]);
                }
            }
            dp[i][last] = mx;
        }
    }
    return dp[n-1][3];
    // return getAns(points, n-1, n, 3, dp);
}