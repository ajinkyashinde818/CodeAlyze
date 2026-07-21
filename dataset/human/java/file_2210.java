import java.io.*;
import java.util.*;

class Main
{
    public static void main(String args[])throws Exception
    {
        BufferedReader bu=new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb=new StringBuilder();
        long n=Long.parseLong(bu.readLine()),i;
        HashMap<Long,Integer> hm=new HashMap<>();
        for(i=2;i*i<=n;i++)
        if(n%i==0)
        {
            int c=0;
            while(n%i==0)
            {
                c++;
                n/=i;
            }
            hm.put(i,c);
        }
        if(n>=2)
        if(hm.get(n)==null) hm.put(n,1);
        else hm.put(n,hm.get(n)+1);
        long c=0;
        for(long x:hm.keySet())
        {
            int cur=1,tot=hm.get(x);
            while(cur<=tot)
            {
                c++;
                tot-=cur;
                cur++;
            }
        }
        System.out.print(c);
    }
}
