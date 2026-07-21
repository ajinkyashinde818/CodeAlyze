import java.io.*;
import java.util.*;

class Main
{
    public static void main(String args[])throws Exception
    {
        BufferedReader bu=new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb=new StringBuilder();
        int n=Integer.parseInt(bu.readLine());
        int i,l=0; boolean oc=false;
        for(i=0;i<n;i++)
        {
            String s[]=bu.readLine().split(" ");
            int d1=Integer.parseInt(s[0]),d2=Integer.parseInt(s[1]);
            if(d1==d2) l++;
            else
            {
                if(l>=3) oc=true;
                l=0;
            }
        }
        if(l>=3) oc=true;
        if(oc) sb.append("Yes\n");
        else sb.append("No\n");
        System.out.print(sb);
    }
}
