import java.util.*;
import java.lang.*;
import java.io.*;
 class Main
{
	public static void main (String[] args) throws java.lang.Exception
	{
	    Scanner sc=new Scanner(System.in);
	   // BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
	    int t=1;
	   // t=sc.nextInt();
	    //int t=Integer.parseInt(br.readLine());
	    while(--t>=0){
	        int n=sc.nextInt();
	        int a[][]=new int[n][2];
	        for(int i=0;i<n;i++){
	            a[i][0]=sc.nextInt();
	            a[i][1]=sc.nextInt();
	        }
	        int k=0;
	        for(int i=0;i<n-2;i++){
	            if(a[i][0]==a[i][1]&&a[i+1][0]==a[i+1][1]&&a[i+2][0]==a[i+2][1]){
	                k=1;
	            }
	            
	        }
	        if(k==1)
	        System.out.println("Yes");
	        else
	        System.out.println("No");
	     
	        
	    }
	    
	}
}
