import java.util.*;
import java.io.*;
public class Main
{
    public static void main(String args[])throws Exception
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw=new PrintWriter(System.out);
        String str[]=br.readLine().split(" ");
        int n=Integer.parseInt(str[0]);
        long k=Long.parseLong(str[1]);
        int next[]=new int[n+1];
        int cnttillthere[]=new int[n+1];
        int cntr=0;
        str=br.readLine().split(" ");
        for(int i=0;i<n;i++)
        next[i+1]=Integer.parseInt(str[i]);
        int nxt=1;
        Arrays.fill(cnttillthere,-1);
        cnttillthere[1]=0;
        while(true)
        {
            if(cnttillthere[next[nxt]]>=0||k==0)
            break;
            cntr++;
            cnttillthere[next[nxt]]=cntr;
            nxt=next[nxt];
            k--;
        }
        if(k==0)
        pw.println(nxt);
        else
        {
            int noe=cntr+1-cnttillthere[next[nxt]];
            k--;
            int rem=(int)(k%noe);
            nxt=next[nxt];
            for(int i=0;i<rem;i++)
            nxt=next[nxt];
            pw.println(nxt);
        }
        pw.flush();
        pw.close();
    }
}
