class Solution {
public:
    string convert(string s, int numRows) {
        vector<vector<char>> arr(numRows);
        if(numRows==1)
            return s;
        int sPtr=0,arrPtr=0;
        int flow=1;
        for(int i=0;i<s.size();i++)
        {
              if(arrPtr==0)
              {
                  arr[arrPtr].push_back(s[i]);
                  flow=1;
                  arrPtr++;
              }
                else if(arrPtr==numRows-1)
                {
                    arr[arrPtr].push_back(s[i]);
                    flow=0;
                    arrPtr--;
                }
            else if(flow==1)
            {
                arr[arrPtr].push_back(s[i]);
                arrPtr++;
            }
            else
            {
                arr[arrPtr].push_back(s[i]);
                arrPtr--;
            }
        }
        
        for(int i=0;i<arr.size();i++)
        {
            for(int j=0;j<arr[i].size();j++)
            {
                s[sPtr]=arr[i][j];
                sPtr++;
            }
        }
        return s;
    }
};