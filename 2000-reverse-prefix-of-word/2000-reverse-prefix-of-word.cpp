class Solution {
public:
    string reversePrefix(string word, char ch) {
        int i=0;
        while(i<word.size())
        {
            if(word[i]==ch)
                break;
            i++;
        }
        if(i==word.size())
            return word;
        int j=0;
        while(j<i)
        {
            char temp=word[j];
            word[j]=word[i];
            word[i]=temp;
            j++;
            i--;
        }
        return word;
    }
};