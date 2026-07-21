//package code;
import java.io.*;
import java.util.*;
import java.math.*;
public class Main
{
    public static int t,Dx ,Dy ,J,ans,n,len=0,answer,q ,k,x ,m, a[],tin[],tout[],discover[],time, b[],count,degree[],parent[] ,parent_count[], size[] ,mat[][] , depth[],pre[],blockSize;
    static long  mod=(long)(1e9) + 7 , dp[],sum ,mod1=(long)(998244353);
    static int[] dx={-1, 1,0,0} , dy={0 ,0 , -1 ,1};
    static boolean visited[],isPandatic[];
    public static TreeSet<Integer> ts[];
    public static LinkedList<Integer> lst ,adj[];
    public static PrintWriter pw;
    public static BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
    public static int max1=2000005;
    public static void main(String[] args){
        new Thread(null,null,"Prabhat Kumar Prajapati",1<<28)
        {
           public void run() 
           {
               try
               {
                   solve();
               }
               catch(Exception e)
               {   
                   e.printStackTrace();
                   System.exit(1);
               }
           }
        }.start();
    }
public static void solve()throws IOException
{
    pw = new PrintWriter(System.out);
    Scanner sc=new Scanner(System.in);
    n=sc.nextInt();
    long k=sc.nextLong();
    a=new int[n];
    for(int i=0;i<n;i++)a[i]=sc.nextInt()-1;

    int cycleLength=0;
    int move=0;
    int[] moveTillIndex=new int[n];
    Arrays.fill(moveTillIndex,-1);
    moveTillIndex[0]=0;
    int pos=0;
    boolean cycle=false;
    while(k>0){
        pos=a[pos];
        move++;
        k--;
        if(cycle){

        }
        else if(moveTillIndex[pos]>=0){
            k%=(move-moveTillIndex[pos]);
            cycle=true;
        }
        else moveTillIndex[pos]=move;
    }
   
    pw.println(pos+1);
    pw.close();
}

// here ans will store number of nodes on longest path
static int dfs(int cur){
    int d1=0;
    int d2=0;
    visited[cur]=true;
    for(int ver:adj[cur]){
        if(visited[ver])continue;
        int x=dfs(ver);
        if(x>d1){
            d2=d1;
            d1=x;
        }
        else if(x>d2){
            d2=x;
        }
        ans=Math.max(ans , d1+d2+1);
    }
    //pw.println((cur+1)  +" "+d1+" "+d2);
    return d1+1;
}
public static long pow(long n,long p,long m)
{
    long  result = 1;
      if(p==0)
        return 1;
    
    while(p!=0)
    {
        if(p%2==1)
            result *= n;
        if(result>=m)
        result%=m;
        p >>=1;
        n*=n;
        if(n>=m)
        n%=m;
    }
    return result;
}

}
