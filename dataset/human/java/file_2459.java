import java.util.Scanner;
public class Main
{
	public static void main(String arg[])
	{
		Scanner in=new Scanner(System.in);
		int n=in.nextInt();
		while(n-->0)
		{
			int ans=0;
			int tmp=1;
			for(int j=0;j<2;j++)
			{
				char ch[]=in.next().toCharArray();
				for(int i=0;i<ch.length;i++)
				{
					if(Character.isDigit(ch[i]))
						tmp=Integer.valueOf(ch[i]-'0');
					else if(ch[i]=='m')
					{
						ans+=1000*tmp;
						tmp=1;
					}
					else if(ch[i]=='c')
					{
						ans+=100*tmp;
						tmp=1;
					}
					else if(ch[i]=='x')
					{
						ans+=10*tmp;
						tmp=1;
					}
					else if(ch[i]=='i')
					{
						ans+=1*tmp;
						tmp=1;
					}
				}
			}
			String re="";
			int m=ans/1000;
			ans=ans-1000*m;
			int c=ans/100;
			ans=ans-100*c;
			int x=ans/10;
			ans=ans-10*x;
			int i=ans;
			if(m!=0)
			{
				if(m==1)
					re+="m";
				else
					re+=m+"m";
			}
			if(c!=0)
			{
				if(c==1)
					re+="c";
				else
					re+=c+"c";
			}
			if(x!=0)
			{
				if(x==1)
					re+="x";
				else
					re+=x+"x";
			}
			if(i!=0)
			{
				if(i==1)
					re+="i";
				else
					re+=i+"i";
			}
			System.out.println(re);
		}
	}
}
