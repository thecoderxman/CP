/* Link to the problem : https://practice.geeksforgeeks.org/problems/minimum-number-of-deletions-and-insertions0209/1

Input: str1 = "heap", str2 = "pea"
Output: 3
Explanation: 2 deletions and 1 insertion
p and h deleted from heap. Then, p is 
inserted at the beginning One thing to 
note, though p was required yet it was 
removed/deleted first from its position 
and then it is inserted to some other 
position. Thus, p contributes one to the 
deletion_count and one to the 
insertion_count.

Approach: Find the lcs count of two strings as that gives the count of common subsequence
Next step to find no of insertions is , we to need to add (lengthofb-lcs) and no of deletions 
would be (lengthofa-lcs)
*/

class Solution{

	public:
	int minOperations(string str1, string str2) 
	{ 
	    int m=str1.length();
	    int n=str2.length();
	    
	    int dp[m+1][n+1];
	    
	    for(int i=0;i<=m;i++)
	    for(int j=0;j<=n;j++) dp[i][j]=0;
	    
	    for(int i=1;i<=m;i++)
	    for(int j=1;j<=n;j++){
	        if(str1[i-1]==str2[j-1]) dp[i][j]=dp[i-1][j-1]+1;
	        else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
	    }
	    
	    return (m-dp[m][n])+(n-dp[m][n]);
	} 
};
