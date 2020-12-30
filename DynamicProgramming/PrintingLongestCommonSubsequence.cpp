/* Link to the question : https://www.hackerrank.com/challenges/dynamic-programming-classics-the-longest-common-subsequence/
Same logic of finding the length of longest common subsequence
After finding the length we traverse back from index m,n and check if a[m]==b[n] and if so then push back the element else move towards the index which has 
max value
*/

vector<int> longestCommonSubsequence(vector<int> a, vector<int> b) {

    vector<int> result;
    int m=a.size();
    int n=b.size();
    
    int dp[m+1][n+1];
    for(int i=0;i<=m;i++)
    for(int j=0;j<=n;j++)
    dp[i][j]=0;
    
    for(int i=1;i<=m;i++)
    for(int j=1;j<=n;j++){
        if(a[i-1]==b[j-1]) dp[i][j]=dp[i-1][j-1]+1;
        else dp[i][j] = max( dp[i-1][j],dp[i][j-1]);
    }
    
    int i=m,j=n;
    while(i>0&&j>0){
        if(a[i-1]==b[j-1]) {
            result.push_back(a[i-1]);
            i--;
            j--;
        }
        else{
            if(dp[i][j-1]>dp[i-1][j])j--;
            else i--;
        }
    }
    reverse(result.begin(),result.end());
    return result;
}
