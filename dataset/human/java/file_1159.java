import java.io.*;
import java.util.*;
import java.lang.*;
import static java.lang.System.*;
public class Main
{
public static void main (String args[]) throws Exception
{
	Scanner sc=new Scanner(in);
    int n=sc.nextInt();
    long arr[]=new long[n];
    long sum=0;
    for(int i=0;i<n;i++)
    {
		arr[i]=sc.nextLong();
		sum+=arr[i];
	}
    int pos=-1;
    long a=0;
    long b=0;
    long min=0;
    int flag=0;
    for(int i=0;i<n-1;i++)
    {
		a+=arr[i];
		b=(sum-a);
		long diff=b-a;
		if(diff<0)
		diff=diff*-1;
		//out.println(diff);
		//out.println(a);

		//out.println(b);
		if(flag==0)
		{
			//out.println("ss");
			flag=1;
			min=diff;
			pos=i;
			//	out.println(Math.abs(b-a));

		}
		else if(diff<min)
		{min=diff;pos=i;	//out.println(Math.abs(b-a));
}
	}
    if(n==2)
	out.println(Math.abs(arr[1]-arr[0]));
	else
	out.println(min);



}
}


class Berland
{
char ch;
int pos;
public Berland(int a,char b)
{
ch=b;
pos=a;
}
}
class ChComparator implements Comparator<Berland>
{
public int compare(Berland f1,Berland f2)
{
if(f1.ch==f2.ch)
return 0;
if(f1.ch<f2.ch)
return -1;
return 1;
}
}
