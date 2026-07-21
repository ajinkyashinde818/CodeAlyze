import java.io.*;
import java.util.*;
public class Main {
    static PrintWriter pw;
    static int[] visit;
    static int max;
    static int[] arr;
    static void dfs(int i, int c) {
       visit[i-1]=c;
       max=Math.max(c, max);
       int lim=arr.length/i;
       for(int j=2; j<=lim; j++){
           if(visit[i*j-1]<c+1 && arr[i*j-1]>arr[i-1]){
               dfs(i*j, c+1);
           }
       }
    }
    public static long gcf(long x, long y) {
        while(x%y!=0 && y%x!=0) {
            if(x>y)
                x%=y;
            else
                y%=x;
        }
        return x>y? y:x;
    }
    static int ceildiv(int x, int y){
        return x%y==0? x/y: x/y+1;
    }
    static int count1s(int x){
        int ans=0;
        while(x>0){
            ans+=(x&1);
            x>>=1;
        }
        return ans;
    }
    static void print(int n){
        while(n-->0)
            pw.print(0+" ");
    }
    static int min=Integer.MAX_VALUE;
    static boolean b=false;
    static void solve(int[][] arr, int[] c, int i, int[] ans, int price, int k){
        if(i==arr.length){
            boolean f=true;
            for(int j=0; j<ans.length && f; j++){
                if(ans[j]<k)
                    f=false;
            }
            if(f) {
                b=true;
                min = Math.min(min, price);
            }
        }else{
            for(int j=0; j<arr[i].length; j++){
                ans[j]+=arr[i][j];
            }
            solve(arr, c, i+1, ans, price+c[i], k);
            for(int j=0; j<arr[i].length; j++){
                ans[j]-=arr[i][j];
            }
            solve(arr, c, i+1, ans, price, k);
        }

    }
    public static void main(String[] args) throws Exception {
        Scanner sc= new Scanner(System.in);
        pw = new PrintWriter(System.out);
        int n=sc.nextInt(),m=sc.nextInt(),x=sc.nextInt();
        int[] c=new int[n];
        int[][] arr=new int[n][m];
        for(int i=0; i<n; i++){
            c[i]=sc.nextInt();
            arr[i]=sc.nextArr(m);
        }
        int[] ans=new int[m];
        solve(arr, c, 0, ans, 0, x);
        pw.println(b? min: -1);
        pw.close();
    }
    static class Scanner {
        StringTokenizer st;
        BufferedReader br;
        public Scanner(InputStream s) {
            br = new BufferedReader(new InputStreamReader(s));
        }

        public Scanner(FileReader r) {
            br = new BufferedReader(r);
        }

        public String next() throws IOException {
            while (st == null || !st.hasMoreTokens())
                st = new StringTokenizer(br.readLine());
            return st.nextToken();
        }

        public int nextInt() throws IOException {
            return Integer.parseInt(next());
        }

        public long nextLong() throws IOException {
            return Long.parseLong(next());
        }

        public String nextLine() throws IOException {
            return br.readLine();
        }

        public double nextDouble() throws IOException {
            return Double.parseDouble(next());
        }

        public int[] nextArr(int n) throws IOException {
            int[] arr = new int[n];
            for (int i = 0; i < arr.length; i++)
                arr[i] = nextInt();
            return arr;
        }
        public Integer[] nextsort(int n) throws IOException{
            Integer[] arr=new Integer[n];
            for(int i=0; i<n; i++)
                arr[i]=nextInt();
            return arr;
        }
        public boolean ready() throws IOException {
            return br.ready();
        }
    }
    static class Pair implements Comparable<Pair>{
        int x;
        int y;
        public Pair(int x, int y) {
            this.x=x;
            this.y=y;
        }
        public int hashCode() {
            return (this.x+""+this.y).hashCode();
        }
        public int compareTo(Pair other) {
            if(this.x!=other.x)
                return this.x-other.x;
            else {
                return this.y-other.y;
            }
        }
        public boolean equals(Object obj) {
            if (obj == null) {
                return false;
            }
            if (this.getClass() != obj.getClass()) {
                return false;
            }
            Pair p = (Pair) obj;
            return this.x == p.x && this.y == p.y;
        }
    }
    static class tuple implements Comparable<tuple>{
        int x;int y;int z;
        public tuple(int x, int y, int z){
            this.x=x;
            this.y=y;
            this.z=z;
        }
        public int compareTo(tuple other) {
            if(this.x!=other.x)
                return this.x-other.x;
            else {
                if(this.y!=other.y)
                    return this.y-other.y;
                else
                    return this.z-other.z;
            }
        }
        public boolean equal(tuple t){
            return this.x==t.x && this.y==t.y;
        }
    }
    static class visit {
        int x;
        boolean y;
        public visit(int x, boolean y){
            this.x=x;
            this.y=y;
        }
    }
}
