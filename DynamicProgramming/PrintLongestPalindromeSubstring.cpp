//Link to the problem: https://practice.geeksforgeeks.org/problems/longest-palindrome-in-a-string/0#

#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	while(t--){
	    string s;
	    cin>>s;
	    string s1;
	    s1=s;
	    int n=s.size(),ans=0,temp=0;
	    reverse(s1.begin(),s1.end());
	    int dp[n+1][n+1];
	    for(int i=0;i<=n;i++) 
	    for(int j=0;j<=n;j++) dp[i][j]=0;
	    for(int i=1;i<=n;i++)
	    for(int j=1;j<=n;j++){
	        if(s[i-1]==s1[j-1]) {
	            dp[i][j]=dp[i-1][j-1]+1;
	            if(dp[i][j]>ans){
	                ans=dp[i][j];
	                temp=i;
	            }
	        }
	        else dp[i][j]=0;
	    }
	    if(ans==1) {
	        cout<<s[0]<<endl;
	        continue;
	    }
	    if(ans==2){
	        if(s[temp-1]!=s[temp-2]) {
	            cout<<s[0]<<endl;
	            continue;
	        }
	    }
	    
	    while(ans--){
	        cout<<s[temp-1];
	        temp--;
	    }
	    cout<<endl;
	}
	return 0;
}
