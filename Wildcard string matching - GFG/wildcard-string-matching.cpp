// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function template for C++
class Solution{
    public:
    bool solve(string wild,string pattern, int index1,int index2)
    {
        if(index1<0&&index2<0)   return true;
        if(index1<0) return false;
        if(index2<0)
        {
            for(int i=0;i<=index1;i++)
            if(wild[i]!='*')    return false;
            return true;
        }
        
        if(wild[index1]==pattern[index2]||wild[index1]=='?')
        return solve(wild,pattern,index1-1,index2-1);
        
        if(wild[index1]=='*')
        {
            bool dontMatch=solve(wild,pattern,index1-1,index2);
            bool match=solve(wild,pattern,index1,index2-1);
            return dontMatch||match;
        }
        
        return false;
    }
    bool match(string wild, string pattern)
    {
        return solve(wild,pattern,wild.size()-1,pattern.size()-1);
        
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string wild, pattern;
        cin>>wild>>pattern;
        
        Solution ob;
        if(ob.match(wild, pattern))
        cout<<"Yes\n";
        else
        cout<<"No\n";
    }
    return 0;
}  // } Driver Code Ends