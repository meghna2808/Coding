#include <bits/stdc++.h> 
bool checkValidString(string s)
{
	int n =s.size();
	if(n==0) return true;
	char first_char=s[0];
	for(int i=1;i<n;i++)
	{
		if(s[i]!=first_char)return false;
	}
	return true;
}
int wordRectangle(vector<string> &words)
{
	int n=words.size();
	int max_size=INT_MIN;
	for(int i=0;i<n;i++)
	{
		if(checkValidString(words[i]))
		{
			max_size=max(max_size,(int)words[i].size());
		}
	}
	if(max_size==INT_MIN) return 0;
	return max_size*max_size;
	// Write your code here.
}