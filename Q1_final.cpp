#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,x;
    cin >> n >> x;
    vector<int> v(n);
    for(int i=0;i<n;i++){
        cin >> v[i];
    }
    vector<int> dp(x+1,0);
    dp[0]=1;
    for(int i=0;i<n;i++){
        for(int j=v[i];j<=x;j++){
            dp[j]=(dp[j]+dp[j-v[i]])%1000000007;
        }
    }
    cout << dp[x];
    return 0;
}







