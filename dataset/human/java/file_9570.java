import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Collections;
import java.util.StringTokenizer;
import java.util.TreeSet;

public class Main {
    public static FastReader fs = new FastReader();
    static PrintWriter out = new PrintWriter(System.out);

    static void solve() {
        int n = fs.nextInt();
        int[] a = new int[n];
        for(int i = 0; i<n; i++){
            a[i] = fs.nextInt()-fs.nextInt();
        }
        TreeSet<Integer> st = new TreeSet<>();
        boolean ok = false;
        for(int i = 0; i<3; i++){
            st.add(a[i]);
        }
        if(st.size() == 1 && st.first() == 0){
            ok = true;
        }
        for(int i = 1; i+3<=n; i++){
            st.clear();
            for(int j = i; j<i+3; j++)
                st.add(a[j]);
            if(st.size() == 1 && st.first() == 0){
                ok = true;
            }
        }
        out.println(ok?"Yes":"No");
    }

    public static void main(String[] args) {
        Thread t = new Thread(null,null,"",1 << 28) {
            public void run() {
                int test_case = 1;
                //test_case = fs.nextInt();
                for(int cs = 1; cs <= test_case; cs++) {
                    solve();
                }
                out.close();
            }
        };
        t.start();
        try {
            t.join();
        } catch (InterruptedException e) {
            e.printStackTrace();
        }
    }
    static class FastReader
    {
        BufferedReader br;
        StringTokenizer st;

        public FastReader()
        {
            br = new BufferedReader(new
                    InputStreamReader(System.in));
        }

        String next()
        {
            while (st == null || !st.hasMoreElements())
            {
                try
                {
                    st = new StringTokenizer(br.readLine());
                }
                catch (IOException  e)
                {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt()
        {
            return Integer.parseInt(next());
        }

        long nextLong()
        {
            return Long.parseLong(next());
        }

        double nextDouble()
        {
            return Double.parseDouble(next());
        }

        String nextLine()
        {
            String str = "";
            try
            {
                str = br.readLine();
            }
            catch (IOException e)
            {
                e.printStackTrace();
            }
            return str;
        }

        int [] readintarray(int n) {
            int res [] = new int [n];
            for(int i = 0; i<n; i++)res[i] = nextInt();
            return res;
        }
        long [] readlongarray(int n) {
            long res [] = new long [n];
            for(int i = 0; i<n; i++)res[i] = nextLong();
            return res;
        }
    }

    static int ceil(int x,int y) {
        return (x % y == 0 ? x / y : (x / y +1));
    }

    static long ceil(long x,long y) {
        return (x % y == 0 ? x / y : (x / y +1));
    }

    static <T extends Comparable<T>> T min(T x, T y) {
        if(x.compareTo(y) <= 0)
            return x;
        return y;
    }

    static <T extends Comparable<T>> T max(T x, T y) {
        if(x.compareTo(y) >= 0)
            return x;
        return y;
    }

    static <T extends Comparable<T>> T max(T[] a){
        T res = a[0];
        for(int i = 1; i<a.length; i++){
            if(res.compareTo(a[i]) >= 0){
                res = a[i];
            }
        }
        return res;
    }

    static <T extends Comparable<T>> T min(T[] a){
        T res = a[0];
        for(int i = 1; i<a.length; i++){
            if(res.compareTo(a[i]) <= 0){
                res = a[i];
            }
        }
        return res;
    }

    static int power(int x,int y) {
        int res = 1;
        while(y > 0) {
            if( y % 2 == 1)res = (res * x);
            y >>= 1;
            x = (x * x);
        }
        return res;
    }

    static long power(long x,long y) {
        long res = 1;
        while(y > 0) {
            if( y % 2 == 1)res = (res * x);
            y >>= 1;
            x = (x * x);
        }
        return res;
    }

    static long power(long x,long y,long mod) {
        long res = 1;
        x %= mod;
        while(y > 0) {
            if( y % 2 == 1)res = (res * x) % mod;
            y >>= 1;
            x = (x * x) % mod;
        }
        return res;
    }

    static <T extends Comparable<T>> void Sort(T[] a){
        ArrayList<T> temp = new ArrayList<>();
        for(int i = 0; i<a.length; i++)temp.add(a[i]);
        Collections.sort(temp);
        for(int i = 0; i<a.length; i++)a[i] = temp.get(i);
    }

    static <T extends Comparable<T>> void Rsort(T[] a){
        ArrayList<T> temp = new ArrayList<>();
        for(int i = 0; i<a.length; i++)temp.add(a[i]);
        Collections.sort(temp);
        Collections.reverse(temp);
        for(int i = 0; i<a.length; i++)a[i] = temp.get(i);
    }

    static <T extends Comparable<T>> void intervalsort(T a [],int start,int end) {
        ArrayList<T> temp = new ArrayList<>();
        for(int i = start; i<end; i++)
            temp.add(a[i]);
        Collections.sort(temp);
        for(int i = 0; i<temp.size(); i++)
            a[i+start] = temp.get(i);
    }
}
