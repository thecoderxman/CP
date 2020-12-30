/*Longest common subsequence
Link to the question : https://practice.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1

Ex: A = 6, B = 6
str1 = ABCDGH
str2 = AEDFHR
Output: 3
Explanation: LCS for input Sequences
“ABCDGH” and “AEDFHR” is “ADH” of
length 3.

Approach: Using top down dp array to store the longest common sequence till that index
If s1[i]==s2[i] then increment the count 
else check for (s1[n-1] and s2[n]) and (s1[n] and s2[n-1]) and take the max of it.
*/


int lcs(int x, int y, string s1, string s2){
    
    int dp[x+1][y+1];
    
    for(int i=0;i<=x;i++)
    for(int j=0;j<=y;j++)
    dp[i][j]=0;
    
    for(int i=1;i<=x;i++){
        for(int j=1;j<=y;j++){
            if(s1[i-1]==s2[j-1]) dp[i][j]=dp[i-1][j-1]+1;
            else dp[i][j]= max(dp[i-1][j],dp[i][j-1]);
        }
    }
    
    return dp[x][y];
    
}
