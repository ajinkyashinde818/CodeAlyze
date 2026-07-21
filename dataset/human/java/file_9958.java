import javax.swing.text.html.HTMLDocument;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.math.BigInteger;
import java.nio.Buffer;
import java.util.*;

class Main {
    public static void main(String[] args){
        try {
            BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
            String[] ss=br.readLine().split(" ");
            int n=Integer.parseInt(ss[0]);
            int m=Integer.parseInt(ss[1]);
            int x=Integer.parseInt(ss[2]);
            int[][] arr=new int[n][m];
            int[] cost=new int[n];
            for(int i=0;i<n;i++){
                ss=br.readLine().split(" ");
                cost[i]=Integer.parseInt(ss[0]);
                for(int j=0;j<m;j++){
                    arr[i][j]=Integer.parseInt(ss[j+1]);
                }
            }
            long ans=Long.MAX_VALUE;
            for(int i=0;i<Math.pow(2,n);i++){
                long c=0;
                int[] aa=new int[m];
                for(int j=0;j<n;j++){
                    if((i&(1<<j))>0){
                        c+=cost[j];
                        for(int k=0;k<m;k++){
                            aa[k]+=arr[j][k];
                        }
                    }
                }
                boolean ff=false;
                for(int j=0;j<m;j++){
                    if(aa[j]<x){
                        ff=true;
                    }
                }
                if(!ff){
                    ans=Math.min(ans,c);
                }
            }
            if(ans!=Long.MAX_VALUE) {
                System.out.println(ans);
            }else{
                System.out.println(-1);
            }
        } catch (Exception e) {
            System.out.println("kkkk "+ e.getMessage());
        }
    }
    static void dfs(ArrayList<HashSet<Integer>> list,boolean[] vis,int i){
        vis[i]=true;
        Iterator<Integer> it=list.get(i).iterator();
        while(it.hasNext()){
            int u=it.next();
            if(!vis[u]){
                dfs(list,vis,u);
            }
        }
    }
    static int modInverse(int x,int m){
        return power(x,m-2,m);
    }
    static int power(int x, int y, int m)
    {
        if (y == 0)
            return 1;

        long p = power(x, y / 2, m) % m;
        p = (p * p) % m;

        return (int)((y%2==0)? p : (x*p)%m);
    }
    static void shuffle(String[] a) {
        Random get = new Random();
        for (int i = 0; i < a.length; i++) {
            int r = get.nextInt(a.length);
            String temp = a[i];
            a[i] = a[r];
            a[r] = temp;
        }
    }
    static class quad{
        int a,b,c,d;
        public quad(int a,int b,int c,int d){
            this.a=a;
            this.b=b;
            this.c=c;
            this.d=d;
        }
    }
}
