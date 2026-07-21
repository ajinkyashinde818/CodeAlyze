import java.io.*;
import java.util.*;
public class Main {

    private static void solver(InputReader sc, PrintWriter out) {
        int n = sc.nextInt();
        long k = sc.nextLong();
        int arr[] = new int[n+1];
        for(int i=1; i<=n; i++) arr[i] = sc.nextInt();
        Set<Integer> hs = new HashSet<>();
        List<Integer> al = new ArrayList<>();
        int x = 1;
        al.add(1);
        hs.add(1);
        while(true){
            x = arr[x];
            if(hs.contains(x)){
                break;
            }else {
                hs.add(x); al.add(x);
            }
        }
        int size = al.size();
        List<Integer> nonreps = new ArrayList<>();
        List<Integer> reps = new ArrayList<>();
        boolean flag = true;
        for (Integer integer : al) {
            if (flag) {
                if (integer == x) {
                    flag = false;
                    reps.add(integer);
                }else{
                    nonreps.add(integer);
                }
            } else {
                reps.add(integer);
            }
        }
        if(k < nonreps.size()){
            out.println(nonreps.get((int)k));
        }else{
            k -= nonreps.size();
         //   out.println(reps.size());
            k %= reps.size();
            out.println(reps.get((int)k));
        }
    }
    public static void main(String[] args) throws Exception {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        PrintWriter out = new PrintWriter(outputStream);
        solver(in,out);
        out.close();
    }

    static class InputReader {
        public BufferedReader reader;
        public StringTokenizer tokenizer;

        public InputReader(InputStream stream) {
            reader = new BufferedReader(new InputStreamReader(stream), 32768);
            tokenizer = null;
        }

        public String next() {
            while (tokenizer == null || !tokenizer.hasMoreTokens()) {
                try {
                    tokenizer = new StringTokenizer(reader.readLine());
                } catch (IOException e) {
                    throw new RuntimeException(e);
                }
            }
            return tokenizer.nextToken();
        }

        public int nextInt() {
            return Integer.parseInt(next());
        }
        public long nextLong() {
            return Long.parseLong(next());
        }
        public int[] readIntArray(int n){
            int arr[] = new int[n];
            for(int i=0;i<n;i++) arr[i] = nextInt();
            return arr;
        }
    }
}
class Pair{
    int x,y;
    Pair(int x, int y){
        this.x = x;
        this.y = y;
    }
}
