import java.util.*;
public class Main {

	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int n=sc.nextInt();
		int m=sc.nextInt();
		char a[][]=new char[n][n];
		char b[][]=new char[m][m];
		for(int i=0;i<n;i++)
		{
			String s=sc.next();
		for(int j=0;j<n;j++)
		{
			a[i][j]=s.charAt(j);
			
		}
		}
		for(int i=0;i<m;i++)
		{
			String s=sc.next();
		for(int j=0;j<m;j++)
		{
			b[i][j]=s.charAt(j);
			
		}
		}
		
		boolean ans=false;
		for(int i=0;i<n-m+1;i++)
		{
		for(int j=0;j<n-m+1;j++)
		{
			if(b[0][0]==a[i][j])
			{
				ans=ch(n,m,a,b,i,j);
				//System.out.println(i+" "+j+" "+b[0][0]+" "+a[i][j]);
			}
			if(ans) break;
		}
		if(ans) break;
		}
		//System.out.println(ans);
		if(ans) System.out.println("Yes");
		else System.out.println("No");
		
	}
	
	public static boolean ch(int n,int m,char a[][],char b[][],int i,int j)
	{
		int ii=i;
		for(int x=0;x<m;x++)
		{ 
			int jj=j;
			for(int y=0;y<m;y++)
			{
				if(b[x][y]!=a[ii][jj]) return false;
				jj++;
			}
			ii++;
		}
		return true;
	}
	
}
