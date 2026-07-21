import java.util.*;
public class Main
{
  public static void main(String args[])
  {
  Scanner sc=new Scanner(System.in);
  int aa=sc.nextInt();
  int b=sc.nextInt();
   int arr[]=new int[b];
 	for(int i=0;i<b;i++)
 	{
 		arr[i]=sc.nextInt();
 	}
 	int  min=Math.min(arr[b-1]-arr[0], aa-arr[b-1]+arr[b-2]);
 	for(int i=1;i<b-1;i++)
 	{
 		int d=Math.min(arr[i]+aa-arr[i+1],aa-arr[i]+arr[i-1]);
 		min=Math.min(d,min);
 	}
 	System.out.println(min);
  }
}
