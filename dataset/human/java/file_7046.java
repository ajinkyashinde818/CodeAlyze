import java.util.*;
public class Main{
  public static void main(String[]args){
    Scanner sc=new Scanner(System.in);
    int p=sc.nextInt();
    int n=sc.nextInt();
    int[] a=new int[n];
	for(int i=0;i<n;i++)
    {
	a[i]=sc.nextInt();
    }        
      Arrays.sort(a);

    int min=a[a.length-1]-a[0];

    for(int i=1;i<a.length;i++)
    {
      int sum=p-(a[i]-a[i-1]);
      if(sum<min)
      {
        min=sum;
      }
    }
    System.out.println(min);
    
  }
}
