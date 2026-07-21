import java.io.*;
import java.util.*;

class Main
{
    public static void main(String args[])throws Exception
    {
        BufferedReader bu=new BufferedReader(new InputStreamReader(System.in));
        String s[]=bu.readLine().split(" ");
        int n=Integer.parseInt(s[0]),i,a[]=new int[n+1];
        long k=Long.parseLong(s[1]);
        s=bu.readLine().split(" ");
        int pos=1,l=1;
        for(i=0;i<n;i++)
            a[i+1]=Integer.parseInt(s[i]);
        ArrayList<Integer> path=new ArrayList<>();
        HashMap<Integer,Integer> hm=new HashMap<>();
        path.add(1);
        hm.put(1,1);
        while(true)
        {
            pos=a[pos];
            if(hm.get(pos)==null)
            {
                path.add(pos);
                hm.put(pos,path.size());
            }
            else {l=hm.get(pos); break;}
        }
        if(k<path.size()) {System.out.print(a[path.get((int)(k-1))]); return;}
        l--;
        k-=l;
        k%=(path.size()-l);
        k--;
        if(k==-1) k=path.size()-l-1;
        System.out.print(a[path.get((int)(l+k))]);
    }
}
