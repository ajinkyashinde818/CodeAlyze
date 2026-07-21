import java.io.*;
import java.sql.SQLSyntaxErrorException;
import java.util.*;
import java.util.zip.Adler32;

public class Main {
    static int count(int[]a,int[]b,int v){
        int count =0;
        for (int i =0;i<a.length;i++){
            count+=getcount(a[i],b,v,2*v);
            count+=getcount(a[i],b,3*v,4*v);
            count&=1;
        }
        return count;
    }
    static int getcount(int v,int []a,int lo,int ho){
        int low =0;
        int hi =a.length-1;
        int ans1=-1,ans2=-1;
        while (low<=hi){
            int mid = low +hi >>1;
            if (a[mid]+v<lo){
                low=mid+1;
            }
            else if (a[mid]+v>=ho){
                hi=mid-1;
            }
            else {
                ans1=mid;
                hi=mid-1;
            }
        }
        low=0;
        hi=a.length-1;
        while (low<=hi){
            int mid = low +hi >>1;
            if (a[mid]+v<lo){
                low=mid+1;
            }
            else if (a[mid]+v>=ho){
                hi=mid-1;
            }
            else {
                ans2=mid;
                low=mid+1;
            }
        }
        return ans1==-1?0:ans2-ans1+1;
    }
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        PrintWriter pw = new PrintWriter(System.out);
        int n = sc.nextInt();
        int[]a= new int[n];
        int[] b = new int[n];
        for (int i =0;i<n;i++)a[i]=sc.nextInt();
        for (int i =0;i<n;i++)b[i]=sc.nextInt();

        int ans =0;
        for (int i =0;i<29;i++){
            int[] ac= new int[n];
            int[] bc= new int[n];
            int mod = (1<<(i+1))-1;
            for (int j=0;j<n;j++){
                ac[j]=a[j]&mod;
                bc[j]=b[j]&mod;
            }
            Shuffle(ac);
            Shuffle(bc);
            Arrays.sort(ac);
            Arrays.sort(bc);
            if (count(ac,bc,1<<i)==1){
                ans|=1<<i;
            }
        }
        pw.println(ans);
        pw.flush();
    }
    public static void Shuffle(int[]a){
        for (int i =0;i<a.length;i++){
            int t = a[i];
            int id = (int)(Math.random()*a.length);
            a[i]=a[id];
            a[id]=t;
        }
    }
    static class Scanner {
        StringTokenizer st;
        BufferedReader br;

        public Scanner(FileReader r) {
            br = new BufferedReader(r);
        }

        public Scanner(InputStream s) {
            br = new BufferedReader(new InputStreamReader(s));
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
            String x = next();
            StringBuilder sb = new StringBuilder("0");
            double res = 0, f = 1;
            boolean dec = false, neg = false;
            int start = 0;
            if (x.charAt(0) == '-') {
                neg = true;
                start++;
            }
            for (int i = start; i < x.length(); i++)
                if (x.charAt(i) == '.') {
                    res = Long.parseLong(sb.toString());
                    sb = new StringBuilder("0");
                    dec = true;
                } else {
                    sb.append(x.charAt(i));
                    if (dec)
                        f *= 10;
                }
            res += Long.parseLong(sb.toString()) / f;
            return res * (neg ? -1 : 1);
        }

        public boolean ready() throws IOException {
            return br.ready();
        }
    }
}
