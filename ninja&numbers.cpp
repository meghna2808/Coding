string findStableNumber(int k, string &s) {
	int n=s.size();
	int j=0;
	int index=k-1;
	bool increment=false;
	for(int i=k;i<n;i++)
	{
		if(s[i]>s[i%k])
		{
			increment=true;
			break;
		}
		else if(s[i]<s[i%k])
		{
			break;
		}
	}
	if(increment==true)
	{
		
		while(index>=0 && s[index]=='9')
			{
				s[index]='0';
				index--;
			}
		
		if(index<0)
		{
			s='1'+s;
			n++;
		}
		else
		{
			
			s[index]=s[index]-'0'+'1';
		}
		
	}
	for(int i=k;i<n;i++)
	{
		
		s[i]=s[i%k];
	}
	return s;
}
