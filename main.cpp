//https://mendo.mk/Task.do?id=24

#include <bits/stdc++.h>  
using namespace std;  
   
   
int main() {  
   
    int N; cin >> N;  
    string S; cin >> S;  
    S = "." + S; //so indexes are 1..N  
   
   
    int dp[N+1][N+1];  
    memset(dp, 0, sizeof(dp));  
   
    for (int len=2; len<N; len++) {  
        for (int i=1; i+len <= N; i++) {  
            int j = i + len;  
   
            bool canConnect = (S[i] == 'A' && S[j] == 'U') || (S[i] == 'U' && S[j] == 'A')  
                    || (S[i] == 'C' && S[j] == 'G') || (S[i] == 'G' && S[j] == 'C')  
                    || (S[i] == 'G' && S[j] == 'U') || (S[i] == 'U' && S[j] == 'G');  
   
            //connect  
            if (canConnect) { dp[i][j] =  dp[i+1][j-1] + 1; }  
   
            //don't connect  
            for (int k=i+1; k<=j; k++) { dp[i][j] = max(dp[i][j], dp[i][k-1] + dp[k][j]); }  
        }  
    }  
   
    cout << dp[1][N] << endl;  
    return 0;  
}  
