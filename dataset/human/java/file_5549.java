import java.io.*;
import java.util.*;
public class Main implements Runnable{
    
    private void solve()throws IOException{
        int n=nextInt();
        int k=nextInt();
        int s=nextInt();
        if(s==(int)(1e9))
        {
            for(int i=1;i<=k;i++)
                out.print(s+" ");
            for(int i=1;i<=n-k;i++)
                out.print(1+" ");
        }
        else
        {
            for(int i=1;i<=k;i++)
                out.print(s+" ");
            for(int i=1;i<=n-k;i++)
                out.print((int)(1e9)+" ");
        }
    }

     
    ///////////////////////////////////////////////////////////

    final long mod=(long)(1e9+7);
    final int inf=(int)(1e9+1);
    final int maxn=(int)(1e6);
    final long lim=(long)(1e18);

    public void run(){
        try{
            br=new BufferedReader(new InputStreamReader(System.in));
            st=null;
            out=new PrintWriter(System.out);

            solve();

            // int t=nextInt();
            // for(int i=1;i<=t;i++){
            //     // out.print("Case #"+i+": ");
            //     solve();
            // }

            br.close();
            out.close();
        }catch(Exception e){
            e.printStackTrace();
            System.exit(1);
        }
    }
    public static void main(String args[])throws IOException{
        new Main().run();
    } 
    int max(int ... a){
        int ret=a[0];
        for(int i=1;i<a.length;i++)
        ret=Math.max(ret,a[i]);
        return ret;
    }
    int min(int ... a){
        int ret=a[0];
        for(int i=1;i<a.length;i++)
        ret=Math.min(ret,a[i]);
        return ret;
    }
    void debug(Object ... a){
        System.out.print("> ");
        for(int i=0;i<a.length;i++)
        System.out.print(a[i]+" ");
        System.out.println();
    }
    void debug(int a[]){debuga(Arrays.stream(a).boxed().toArray());}
    void debug(long a[]){debuga(Arrays.stream(a).boxed().toArray());}
    void debuga(Object a[]){
        System.out.print("> ");
        for(int i=0;i<a.length;i++)
        System.out.print(a[i]+" ");
        System.out.println();
    }
    BufferedReader br;
    StringTokenizer st;
    PrintWriter out;
    String nextToken()throws IOException{
        while(st==null || !st.hasMoreTokens())
        st=new StringTokenizer(br.readLine());
        return st.nextToken();
    }
    String nextLine()throws IOException{
        return br.readLine();
    }
    int nextInt()throws IOException{
        return Integer.parseInt(nextToken());
    }
    long nextLong()throws IOException{
        return Long.parseLong(nextToken());
    }
    double nextDouble()throws IOException{
        return Double.parseDouble(nextToken());
    }
}
