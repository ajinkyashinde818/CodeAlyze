/* package codechef; // don't place package name! */

import java.util.*;
import java.lang.*;
// import java.math.*;
import java.io.*;

/* Name of the class has to be "Main" only if the class is public. */
public class Main
{
	public static void main (String[] args) throws java.lang.Exception
	{
		// your code goes here
		try{
            BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
            PrintWriter ot=new PrintWriter(System.out);
            int n=Integer.parseInt(br.readLine().trim());
            
            int total=0;
            int a[][]=new int[n][2];
            for(int i=0;i<n;i++)
            {
                String s[]=br.readLine().trim().split(" ");
                for(int j=0;j<2;j++)
                {
                    a[i][j]=Integer.parseInt(s[j]);
                }
            }
            boolean bool=false;
            for(int i=0;i<n-2;i++)
            {
                if(a[i][0]==a[i][1]&&a[i+1][0]==a[i+1][1]&&a[i+2][0]==a[i+2][1])
                {
                    bool=true;
                    break;
                }
            }
            if(bool)
            ot.println("Yes");
            else
            ot.println("No");
            // while(t-->0)
            // {
                
            // }
            br.close();
            ot.close();
                        
        } catch(Exception e){
            System.err.println("ERROR");
            return;
        }
    }
}
