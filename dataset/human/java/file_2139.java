import java.util.*;
import java.io.*;
import java.math.*;
public class Main
{
  
    public static void main(String args[])
    {
        Scanner sc=new Scanner(System.in);
        {
            long n=sc.nextLong();
        
  
        int ans=0;
        HashSet<Long> hs=new HashSet<>();
        for (int i = 2; i <= Math.sqrt(n); i++) 
        { 
            
            int q=1;
            while (n%(long)Math.pow(i,q) == 0) 
            { 
               
                n /= (long)Math.pow(i,q) ;
                hs.add((long)Math.pow(i,q) );
                q++;
                ans++;
            } 
            while(n%i==0)
            n/=i;
        } 
  
       
        if (n>2&&(hs.contains(n)==false))
        ans++;
            System.out.print(ans); 
        }
            
    }
   
}
