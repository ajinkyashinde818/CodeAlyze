import java.util.*;
import java.io.*;
public class Main{
   
public static void main (String[] args) {
    Scanner sc=new Scanner(System.in);
    int n=sc.nextInt();
    int k=sc.nextInt();
    int s=sc.nextInt();
    if(k==0)
    {
        if(s==1)
        {
            for(int i=0;i<n;i++)
            System.out.print((s+1)+" ");
            System.out.println();
        }
        if(s!=1)
        {
             for(int i=0;i<n;i++)
            System.out.print((s-1)+" ");
            System.out.println();
        }
    }
    if(k==n)
    {
            for(int i=0;i<n;i++)
            System.out.print(s+" ");
            System.out.println();
    }
    if(k>0&&k<n)
    {
        for(int i=0;i<k;i++)
        System.out.print(s+" ");
        for(int i=k;i<n;i++)
        System.out.print((s!=1000000000?s+1:s-1)+" ");
        System.out.println();
    }
}
}
