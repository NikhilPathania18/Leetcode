class Solution {
public:
    bool canConstruct(string &ransomNote, string &magazine) {
        unordered_map<char,int> m;
        int size1=ransomNote.size(),size2=magazine.size();
        
        for(int i=0;i<size2;i++)
            m[magazine[i]]++;
        
        for(int i=0;i<size1;i++)
        {
            if(m[ransomNote[i]]==0)    return false;
            m[ransomNote[i]]--;
        }
        return true;
    }
};