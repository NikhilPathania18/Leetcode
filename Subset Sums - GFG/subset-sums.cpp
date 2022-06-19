// { Driver Code Starts
#include<bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
    void sum(vector<int> &nums,vector<int> &arr,int index,int s,vector<int> &ans)
    {
        if(index==nums.size())
        {
            ans.push_back(s);
            return;
        }
        
        arr.push_back(nums[index]);
        sum(nums,arr,index+1,s+nums[index],ans);
        arr.pop_back();
        sum(nums,arr,index+1,s,ans);
    }
    vector<int> subsetSums(vector<int> arr, int N)
    {
        // Write Your Code here
        vector<int> ds;
        vector<int> ans;
        sum(arr,ds,0,0,ans);
        
        sort(ans.begin(),ans.end());
        return ans;
    }
};

// { Driver Code Starts.
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0 ; i < N ; i++){
            cin >> arr[i];
        }
        Solution ob;
        vector<int> ans = ob.subsetSums(arr,N);
        sort(ans.begin(),ans.end());
        for(auto sum : ans){
            cout<< sum<<" ";
        }
        cout<<endl;
    }
    return 0;
}  // } Driver Code Ends