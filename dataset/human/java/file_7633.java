import java.util.*;
import java.io.*;
public class Main
{
    static BufferedReader br;
    static BufferedWriter bw;
    static void solve()throws Exception
    {
        Scanner S = new Scanner(System.in);
        int  n = S.nextInt();
        long k = S.nextLong();
        int A[] = new int[n];
        for(int i=0;i<n;i++)
        A[i] = S.nextInt()-1;
        ArrayList<Integer> al = new ArrayList<Integer>();
        HashSet<Integer> hs  = new HashSet<Integer>();
        ArrayList<Integer> ans = new ArrayList<Integer>();
        int ptr = 0;
        for(int i=0;i<Math.min(k,n);i++)
        {
            if(hs.contains(ptr))
            break;
            al.add(A[ptr]);
            hs.add(ptr);
            ptr = A[ptr];
        }
        int noncycle = al.size();
        hs = new HashSet<Integer>();
        while(!hs.contains(ptr))
        {
            ans.add(ptr);
            hs.add(ptr);
            ptr = A[ptr];
        }
        if(k<=noncycle)
        {
            bw.write(Integer.toString(al.get((int)k-1)+1));
        }
        else
        bw.write(Integer.toString(ans.get((int)((k-noncycle)%ans.size()))+1));
        // System.out.println(al);
    }
    public static void main(String []args)throws Exception
    {
        br = new BufferedReader(new InputStreamReader(System.in));
        bw = new BufferedWriter(new OutputStreamWriter(System.out));
        solve();
        br.close();
        bw.close();
    }
}
