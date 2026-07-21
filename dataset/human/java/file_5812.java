import java.io.*;
import java.math.*;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        InputStream inputStream = System.in;
        OutputStream outputStream = System.out;
        InputReader in = new InputReader(inputStream);
        OutputWriter out = new OutputWriter(outputStream);
        Solver solver = new Solver();
        solver.solve(in,out);
        out.close();

    }

    static class Solver{
        boolean[] visited;
        ArrayList<Integer>[] adjList;

        public void solve(InputReader in, OutputWriter out){
            char[] s = in.next().toCharArray();
            int a =0;
            int b=0;
            int c=0;
            for(char i:s){
                switch (i){
                    case 'a':a++; break;
                    case 'b':b++; break;
                    case 'c': c++; break;
                }
            }
            if(a==b && a==c && a==1){
                out.printf("Yes");
            }
            else{
                out.printf("No");
            }

        }


        private void dfs(int u){
            visited[u] = true;
            for(int v: adjList[u]){
                if(!visited[v]){
                    dfs(v);
                }
            }
        }

        private void bfs(int s) {
            Queue<Integer> q = new LinkedList<Integer>();
            q.add(s);
            visited[s] = true;
            while(!q.isEmpty()) {
                int u = q.remove();
                for(int v: adjList[u])
                    if(!visited[v]) {
                        visited[v] = true;
                        q.add(v);
                    }
            }
        }

        private  int[] nextAInt(int n, InputReader in){
            int arr[] = new int[n];
            for(int i=0;i<n;i++){
                arr[i]= in.nextInt();
            }
            return arr;
        }

    }


    static class InputReader {
        private InputStream stream;
        private byte[] buf = new byte[1 << 16];
        private int curChar;
        private int numChars;

        public InputReader(InputStream stream) {
            this.stream = stream;
        }

        public int read() {
            if (this.numChars == -1) {
                throw new InputMismatchException();
            } else {
                if (this.curChar >= this.numChars) {
                    this.curChar = 0;

                    try {
                        this.numChars = this.stream.read(this.buf);
                    } catch (IOException var2) {
                        throw new InputMismatchException();
                    }

                    if (this.numChars <= 0) {
                        return -1;
                    }
                }

                return this.buf[this.curChar++];
            }
        }

        public int nextInt() {
            int c;
            for (c = this.read(); isSpaceChar(c); c = this.read()) {
                ;
            }

            byte sgn = 1;
            if (c == 45) {
                sgn = -1;
                c = this.read();
            }

            int res = 0;

            while (c >= 48 && c <= 57) {
                res *= 10;
                res += c - 48;
                c = this.read();
                if (isSpaceChar(c)) {
                    return res * sgn;
                }
            }

            throw new InputMismatchException();
        }

        public String next() {
            int c;
            while (isSpaceChar(c = this.read())) {
                ;
            }

            StringBuilder result = new StringBuilder();
            result.appendCodePoint(c);

            while (!isSpaceChar(c = this.read())) {
                result.appendCodePoint(c);
            }

            return result.toString();
        }

        public static boolean isSpaceChar(int c) {
            return c == 32 || c == 10 || c == 13 || c == 9 || c == -1;
        }

    }

    static class OutputWriter {
        private final PrintWriter writer;

        public OutputWriter(OutputStream outputStream) {
            writer = new PrintWriter(new BufferedWriter(new OutputStreamWriter(outputStream)));
        }

        public OutputWriter(Writer writer) {
            this.writer = new PrintWriter(writer);
        }

        public void printf(String format, Object... objects) {
            writer.printf(format, objects);
        }

        public void close() {
            writer.close();
        }

    }


}
