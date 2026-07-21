import java.util.*;
public class Main{
  public static void main(String[] args)
  {
    Scanner sc=new Scanner(System.in);
    int n=sc.nextInt();
    int[] a=new int[n*2];
    for(int i=0;i<n*2;i++)
    {
        a[i]=sc.nextInt();
    }
    int ans=0;
    for(int j=0;j<=(n*2)-6;j++)
    {
      if(a[j]==a[j+1])
      {
         if(a[j+2]==a[j+3])
         {
           if(a[j+4]==a[j+5])
           {
               ans=1;
           }
         }
      }
    }
    if(ans==1)
      	System.out.println("Yes");
    else
      System.out.println("No");
      
  }
}
