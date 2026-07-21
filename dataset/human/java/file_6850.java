//created by Whiplash99
import java.io.*;
import java.util.*;
public class Main
{
    public static void main(String[] args) throws IOException
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));

        int i,N;

        String s[]=br.readLine().trim().split(" ");
        int K=Integer.parseInt(s[0]);
        N=Integer.parseInt(s[1]);

        int a[]=new int[N*2];
        s=br.readLine().trim().split(" ");
        for(i=0;i<N;i++)
            a[i]=Integer.parseInt(s[i]);
        for(i=N;i<2*N;i++) a[i]=a[i-N];

        int min=Integer.MAX_VALUE;
        for(i=0;i<N;i++)
        {
            if(a[i+N-1]>a[i]) min=Math.min(min,a[i+N-1]-a[i]);
            else min=Math.min(min,K-a[i]+a[i+N-1]);
        }
        System.out.println(min);
    }
}
