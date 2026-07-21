import java.io.*;
import java.math.*;
import java.security.*;
import java.text.*;
import java.util.*;
import java.util.concurrent.*;
import java.util.function.*;
import java.util.regex.*;
import java.util.stream.*;
import static java.util.stream.Collectors.joining;
import static java.util.stream.Collectors.toList;

public class Main
{
    public static void main(String[] args)
    {
        Scanner in = new Scanner(System.in);
        int n=in.nextInt();
        int[] d1=new int[n];
        int[] d2=new int[n];
        for(int i=0;i<n;i++)
        {
            d1[i]=in.nextInt();
            d2[i]=in.nextInt();
        }
        boolean flag=false;
        for(int i=0;i<=n-3;i++)
        {
            if(d1[i]==d2[i] && d1[i+1]==d2[i+1] && d1[i+2]==d2[i+2])
            {
                flag=true;
                break;
            }
        }
        if(flag==true)
            System.out.println("Yes");
        else
            System.out.println("No");
    }

}
