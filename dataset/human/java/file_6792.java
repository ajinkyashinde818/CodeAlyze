import java.util.*;
public class Main
{
public static void main(String[] args) {
Scanner sc=new Scanner(System.in);
int k=sc.nextInt();
int n=sc.nextInt();
int a[]=new int[n];
for(int i=0;i<n;i++)
a[i]=sc.nextInt();
int m=0;
for(int i=0;i<n-1;i++)
{
	if(i==0)
	{
		int t=a[i]-a[n-1]+k;
		m=Math.max(m,t);
	}
	else
	{
		m=Math.max(m,(a[i+1]-a[i]));
	}		
}
int z=m;
System.out.println(k-z);
}

}
