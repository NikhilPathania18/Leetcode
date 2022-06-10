class Solution {
public:
    string interpret(string command) {
        string a;
        for(int i=0;i<command.size();i++)
        {
            if(command[i]=='G')
                a.push_back('G');
            else if (command[i]=='('&&command[i+1]==')')
            {
                a.push_back('o');
                i++;
            }
            else 
            {
                a.append("al");
                i+=3;
            }
            
            
        }
        return a;
    }
};