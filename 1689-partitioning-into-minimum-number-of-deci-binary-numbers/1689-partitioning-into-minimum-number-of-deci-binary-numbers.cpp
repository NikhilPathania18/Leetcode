class Solution {
public:
    int minPartitions(string n) {
        char a=n[0];
        for(int i=0;i<n.size();i++)
        {
            if(n[i]>a)
                a=n[i];
            if(a=='9')
                return 9;
        }
        return a-'0';
    }
};