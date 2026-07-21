import java.util.*;
import java.io.*;
class Main
{
 	public static void main (String[]args){
      Scanner sc=new Scanner(System.in);
      int A=sc.nextInt(),B=sc.nextInt(),C=sc.nextInt();
      int ans=0;
      if(B>=C-1)
        ans=B+C;
      else
      {
        ans=2*B;
        C-=B;
        int x=Math.min(C,A);
        ans+=x;
        C-=x;
        if(C>0)
          ans++;
      }
      System.out.println(ans);
      
        
    }
  
}
