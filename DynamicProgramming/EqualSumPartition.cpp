Link to the question : https://leetcode.com/problems/partition-equal-subset-sum/

class Solution {
public:
    bool canPartition(vector<int>& nums) {
      
        //Intitalise sum=0      
        int sum=0;
        int n=nums.size();
        
        for(int i=0;i<n;i++) sum+=nums[i];
        
        //checking if sum is odd then there is no way to divide it into equal partition, so returning false
        if(sum%2) return false;
        
        // divide the sum by 2 and check whether there is a subset with that sum
        sum/=2;
        
        int dp[n+2][sum+2];
        
        //intitalising the dp array 
        for(int i=0;i<=sum;i++)
            dp[0][i]=false;
        for(int i=0;i<=n;i++)
            dp[i][0]=true;
            
        //main dp logic
        /* starting from top as this is top-down dp approach and in every iteration checking if the current element from the array if less than the sum ie.j
        in the code where j presents the sum in the matrix and i represent the i'th element from the array
        */
        for(int i=1;i<=n;i++)
            for(int j=1;j<=sum;j++){
                if(nums[i-1]<=j){
                /* updating the dp table with or operation as this returns the positive result,ie. if the subset exists or not
                Here two cases are considered 1. with including the element by which we reduce the j'th index with that value 
                2.Without including the present value and fetching the value from the previous iteration and checking for the best */
                    dp[i][j]=dp[i-1][j-nums[i-1]]||dp[i-1][j];
                }
                else dp[i][j]=dp[i-1][j];
            }
         // finally returning the dp[n][sum] as it contains the result
        return dp[n][sum];
    }
};
