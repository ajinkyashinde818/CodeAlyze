#include<iostream>
#include<algorithm>
#include<cmath>
#include <iomanip>

using namespace std;


int main()
{
  int q;
  cin>>q;
  for(;q--;)
    {
      string s;
      cin>>s;
      bool bit[32];
      int bitcnt=0;

      for(int i=7;i>=0;i--)
	{
	  int tmp;
	  if(s[i]>='0' &&s[i]<='9')
	    tmp=s[i]-'0';
	  else
	    tmp=10+(s[i]-'a');	  
	  for(int j=0;j<4;j++)
	    {
	      if((1&tmp)>0)
		bit[bitcnt]=true;
	      else 
		bit[bitcnt]=false;
	      tmp>>=1;
	      bitcnt++;
	    }
	}
      /*      for(int i=31;i>=0;i--)
	cout<<bit[i];
      */
      if(bit[31])
	cout<<"-";
      long double ans=0;
      for(int i=7;i<31;i++)
	{
	  if(bit[i])
	    ans+=pow(2,i-7);
	}
      //      cout<<ans;
      //      ans=0;
      // double ans2=0;
      bool flag=true;
      for(int i=6;i>=0;i--)
	{
	  if(bit[i])
	    {
	      ans+=pow(0.5,6-i+1);
	      flag=false;
	    }
	}
      /*      while(ans2!=(int)ans2)
	{
	  ans2*=10;
	  }*/
      //std::cout.setf(std::ios_base::fixed,std::ios_base::floatfield);
      cout<<setprecision(15)<<ans;
      if(flag)
	cout<<".0";
      //      else      
      cout<<endl;
    }
}
