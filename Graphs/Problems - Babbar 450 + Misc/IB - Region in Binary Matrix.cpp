int helper(vector<vector<int>>&v,int i,int j)
{
    v[i][j]=0;
    int ans=1,row=v.size(),col=v[0].size();
    if(i>0 && v[i-1][j]==1)
    {
        ans+=helper(v,i-1,j);
    }
    if(i>0 && j<col-1 && v[i-1][j+1]==1)
    {
        ans+=helper(v,i-1,j+1);
    }
    if(j<col-1 && v[i][j+1]==1)
    {
        ans+=helper(v,i,j+1);
    }
    if(i<row-1 && j<col-1 && v[i+1][j+1]==1)
    {
        ans+=helper(v,i+1,j+1);
    }
    if(i<row-1 && v[i+1][j]==1)
    {
        ans+=helper(v,i+1,j);
    }
    if(i<row-1 && j>0 && v[i+1][j-1]==1)
    {
        ans+=helper(v,i+1,j-1);
    }
    if(j>0 && v[i][j-1]==1)
    {
        ans+=helper(v,i,j-1);
    }
    if(i>0 && j>0 && v[i-1][j-1]==1)
    {
        ans+=helper(v,i-1,j-1);
    }
    return ans;
}
int Solution::solve(vector<vector<int> > &A) 
{
    int count=0,i,j;
    for(i=0;i<A.size();i++)
    {
        for(j=0;j<A[0].size();j++)
        {
            if(A[i][j]==1)
            {
                count=max(count,helper(A,i,j));
            }
        }
    }
    return count;
}
