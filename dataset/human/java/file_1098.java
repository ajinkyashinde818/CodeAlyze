import java.io.*;
import java.util.*;

class Main
{
    public static void main(String args[])throws Exception
    {
        BufferedReader bu=new BufferedReader(new InputStreamReader(System.in));
        StringBuilder sb=new StringBuilder();
        int n=Integer.parseInt(bu.readLine());
        int a[]=new int[n],b[]=new int[n],i;
        String s[]=bu.readLine().split(" ");
        for(i=0;i<n;i++)
        a[i]=Integer.parseInt(s[i]);
        s=bu.readLine().split(" ");
        for(i=0;i<n;i++)
        b[i]=Integer.parseInt(s[i]);

        Queue<Integer> q=new LinkedList<>();
        for(i=0;i<n;i++)
        {
            if(a[i]==b[i])
            {
                if(q.isEmpty()) q.add(i);
                else
                {
                    if(a[q.peek()]!=b[i])
                    {
                        int t=q.poll();
                        b[t]=b[i];
                        b[i]=a[t];
                    }
                    else q.add(i);
                }
            }
        }

        int sz=0;
        while(!q.isEmpty() && q.size()!=sz)
        {
            sz=q.size();
            for(i=0;i<n;i++)
            if(a[i]!=b[i] && !q.isEmpty() && a[i]!=a[q.peek()] && b[i]!=a[q.peek()])
            {
                int t=q.poll();
                b[t]=b[i];
                b[i]=a[t];
            }
        }
        if(!q.isEmpty()) sb.append("No");
        else
        {
            sb.append("Yes\n");
            for(i=0;i<n;i++)
            sb.append(b[i]+" ");
        }
        System.out.print(sb);
    }
}
