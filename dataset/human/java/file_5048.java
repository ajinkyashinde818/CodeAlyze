//package AtCoder.ABC158;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.util.ArrayDeque;
import java.util.Deque;
import java.util.LinkedList;
import java.util.StringTokenizer;

public class Main {

    public static void main(String[] args) {
        Deque<Character> que = new LinkedList<>();
        String ini = in.next();
        for (int i=0;i<ini.length();i++) que.addLast(ini.charAt(i));
        int q = in.NI();

        int flipcoun = 0;
        for (int i=0;i<q;i++) {
            int type = in.NI();
            if (type==1) {  flipcoun++; continue;}
            else {
                int subtype = in.NI(); String ch = in.next();
                if (flipcoun%2==0) {
                    if (subtype==2) que.addLast(ch.charAt(0));
                    else que.addFirst(ch.charAt(0));
                } else {
                    if (subtype==2) que.addFirst(ch.charAt(0));
                    else que.addLast(ch.charAt(0));
                }
            }
        }

        if(flipcoun%2==0) {
            while(que.size()>0) {
                out.print(que.poll());
            }
        } else {
            while(que.size()>0) {
                out.print(que.pollLast());
            }
        }
        out.println();
        out.close();
    }


    static InputStream inputStream = System.in;
    static OutputStream outputStream = System.out;
    static InputReader in = new InputReader(inputStream);
    static PrintWriter out = new PrintWriter(outputStream);

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

        public int NI() {
            return Integer.parseInt(next());
        }

        public long NL() {
            return Long.parseLong(next());
        }

    }
}
