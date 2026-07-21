import java.util.Scanner;

public class Main
{
    public static void main(String[] args) 
    {
       Scanner sc=new Scanner(System.in);
       int k=sc.nextInt(), n=sc.nextInt(),ans=-1;
       int a[]=new int[n];
       a[0]=sc.nextInt();
       for(int i=1; i<n; i++)
       {
            a[i]=sc.nextInt();
            ans=Math.max(ans, Math.abs(a[i]-a[i-1]));            
       }
       ans=Math.max(ans,k- Math.abs(a[0]-a[n-1]));
       System.out.println(k-ans);
              
    }

    
}
