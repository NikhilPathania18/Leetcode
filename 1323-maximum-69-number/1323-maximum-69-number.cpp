class Solution {
public:
    int maximum69Number (int num) {
        string s;
        s=to_string(num);
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='6')
            {
                s[i]='9';
                break;
            }
        }
        num=0;
        int i=0;
        while(i<s.size())
        {
            num+=(int(s[i])-48)*pow(10,s.size()-i-1);
            i++;
        }
        return num;
    }
};