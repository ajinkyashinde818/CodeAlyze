import java.io.*;

class Main
{
	public static void main (String[] args) throws Exception
	{
		BufferedReader bu=new BufferedReader(new InputStreamReader(System.in));
		String s[]=bu.readLine().split(" ");
		int k=Integer.parseInt(s[0]),n=Integer.parseInt(s[1]);
		int a[]=new int[n],i;
		s=bu.readLine().split(" ");
		for(i=0;i<n;i++)
		a[i]=Integer.parseInt(s[i]);
		int min=a[n-1]-a[0];
		for(i=1;i<n;i++)
		{
			int temp=a[i-1]+(k-a[n-1])+(a[n-1]-a[i]);
			if(temp<min) min=temp;
		}	
		System.out.print(min);
	}
}
