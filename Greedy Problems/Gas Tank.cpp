int minimumStartingIndex(vector<int> &gas, vector<int> &cost, int n) 
{
    for(int i=0;i<n;i++)
    {
        if(gas[i]<cost[i])
        {
            continue;
        }
        int gasLeft = 0;
        int j=0;
        
        for(j=i;j<i+n;j++)
        {
            gasLeft += gas[j%n] - cost[j%n];
            
            if(gasLeft<0)
            {
                i = j%n;
                break;
            }
        }
        
        if(gasLeft >=0)
        {
            return i;
        }
        
        else if(j==i+n)
        {
            return -1;
        }
    }
    return -1;
}
