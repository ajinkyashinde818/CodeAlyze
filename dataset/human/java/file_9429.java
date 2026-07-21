import java.util.Scanner;
import java.util.Arrays;
/* Name of the class has to be "Main" only if the class is public. */
public class Main
{
	public static void main (String[] args) throws java.lang.Exception
	{
		try {
		    Scanner sc = new Scanner(System.in);
		    int t,n,i,a,b,k,m;
		    n=sc.nextInt();
		    
		        m=k=0;
		        for(i=0;i<n;i++)
		        {
		            a=sc.nextInt();
		            b=sc.nextInt();
		            if(a==b)
		             k++;
		             else
		             {
		          
		                 if(k>m)
		                 m=k;
		                 k=0;
		             }
		        }
		         if(k>m)
		                 m=k;
		        if(m>=3)
		        System.out.println("Yes");
		        else
		       System.out.println("No");
		    }
		 catch(Exception e) {
		}
	}
}
