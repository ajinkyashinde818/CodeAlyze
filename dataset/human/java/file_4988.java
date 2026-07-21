import java.io.*;
import java.util.*;
public class Main {
    private static void solver(InputReader sc, PrintWriter out) throws Exception {
        String main = sc.next();
       StringBuilder sb = new StringBuilder();
        int q = sc.nextInt();
        boolean flag = true;
        List<String> front = new ArrayList<>();
        List<String> back = new ArrayList<>();
        for (int i = 0; i < q; i++) {
            int x = sc.nextInt();
            if(x==1) {
                flag = !flag;
            }
            else if (x==2){
                int z = sc.nextInt();
                String s = sc.next();
                if(!flag){
                    if(z==1) z = 2;
                    else z = 1;
                }
                if(z==1){
                 //   out.println(s+" "+"front");
                   front.add(s);
                }else{
               //     out.println(s+" "+"bac");
                    back.add(s);
                }
            }
        }
        for(int i=front.size()-1; i>=0; i--){
            sb.append(front.get(i));
        }
        sb.append(main);
        for (String s : back) sb.append(s);
        if(!flag) sb.reverse();
        out.println(sb);
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
        public double nextDouble(){
            return Double.parseDouble(next());
        }
    }
}
class Pair {
   int x,y;
   Pair(int x, int y){
       this.x = x;this.y = y;
   }
    @Override
    public boolean equals(Object o) {
        if (this == o) return true;
        if (o == null || getClass() != o.getClass()) return false;
        Pair pair = (Pair) o;
        return x == pair.x &&
                y == pair.y;
    }

    @Override
    public int hashCode() {
        return Objects.hash(x, y);
    }
}
