import java.io.*;
import java.util.*;
public class Main
{
	public static void main(String[] args)throws IOException {
		InputStreamReader read=new InputStreamReader(System.in);
		BufferedReader in=new BufferedReader(read);
		String str=in.readLine();
		String line[]=str.trim().split(" ");
		int k=Integer.parseInt(line[0]);
		int n=Integer.parseInt(line[1]);
		String st=in.readLine();
		int a[]=new int[n];
		int diff[]=new int[n];
		String l[]=st.trim().split(" ");
		int i;
		for(i=0;i<n;i++)
		{
		    a[i]=Integer.parseInt(l[i]);
		}
		diff[0]=a[0];
		for(i=1;i<n;i++)
		{
		    diff[i]=a[i]-a[i-1];
		}
		Arrays.sort(diff);
		int ans=Math.max((k-a[n-1]+a[0]),diff[n-1]);
		System.out.println((k-ans));
	}
}
