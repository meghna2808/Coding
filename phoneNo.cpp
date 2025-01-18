class Solution {
public:
    void getLetters(vector<string>&digitsToLetters,vector<string>&ans,string digits, int index,string result)
    {
        if(index==digits.size())
        {
            ans.push_back(result);
            return ;
        }
        string letters=digitsToLetters[digits[index]-'2'];
        for(int i=0;i<letters.size();i++)
        {
            getLetters(digitsToLetters,ans,digits,index+1,result+letters[i]);

        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string>digitsToLetters={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string>ans;
        if(digits.size()==0) return ans;
        getLetters(digitsToLetters,ans,digits,0,"");
        return ans;
        
    }
};
//time :O(3^n)
space:O(n*3^n);