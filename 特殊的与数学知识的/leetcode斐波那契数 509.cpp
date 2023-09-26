//
// Created by 16537 on 2023/9/26.
//
#include <iostream>
#include <vector>
#include <algorithm>
class Solution {
public:
    int fib(int n) {
        if (n < 1) {
            return 0;
        }
       std:: vector<int> dp(n + 1);
        dp[0] = 0, dp[1] = 1;
        for (int i = 2; i <= n; ++i) {
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};
