//    package com.company;

    import java.io.*;
    import java.util.*;

    public class Main {

        public static void main(String[] args) throws IOException{
            InputStream inputStream = System.in;
            OutputStream outputStream = System.out;
            InputReader in = new InputReader(inputStream);
            PrintWriter out = new PrintWriter(outputStream);
            Program solver = new Program();
            solver.solve(in, out);
            out.close();
        }

        static class Program{

            static void solve(InputReader in, PrintWriter out) throws IOException{
               int n = in.nextInt();
               int q = n % 10;
               int w = n / 10;
               if(q == 9 || w == 9)out.print("Yes");else out.print("No");
            }

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

            public String nextLine(){
                try {
                    return reader.readLine();
                }catch(IOException e){
                    return null;
                }
            }

        }
    }
