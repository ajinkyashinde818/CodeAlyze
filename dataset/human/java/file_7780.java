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
            long k=Long.parseLong(ss[1]);
            ss=br.readLine().split(" ");
            int[] arr=new int[n];
            for(int j=0;j<n;j++){
                arr[j]=Integer.parseInt(ss[j]);
            }
            int i=0;
            int[] vis=new int[n];
            int p=1;
            vis[i]=1;
            while(k>0){
                i=arr[i]-1;
                k--;
                p++;
                if(vis[i]!=0){
                    int u=p-vis[i];
                    k=k%u;
                    while(k>0){
                        i=arr[i]-1;
                        k--;
                    }
                }else{
                    vis[i]=p;
                }

            }
            System.out.println(i+1);

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
