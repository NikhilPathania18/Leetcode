class Solution {
public:
    int minPartitions(string n) {
        char a=n[0];
        for(int i=0;i<n.size();i++)
        {
            if(a=='9')
                return 9;
            if(n[i]>a)
                a=n[i];
        }
        return a-'0';
    }
};