import java.io.*;
import java.math.*;
import java.util.*;
import java.util.stream.*;

class Main {
    public static void main(String[] args) throws IOException {
        int[] inputs = receiveIntArray(Delimiter.SPACE);
        int length = inputs[0];
        int num = inputs[1];
        int sum = inputs[2];

        if (length == num) {
            for (int i = 0; i < length - 1; i++) {
                print(sum);
                print(" ");
            }
            print(sum);
        }
        else if(num == 0) {
            for (int i = 0; i < length - 1; i++) {
                print(sum != 1000000000 ? sum + 1 : 2);
                print(" ");
            }
            print(sum != 1000000000 ? sum + 1 : 2);
        }
        else if (sum == 1) {
            for (int i = 0; i < num - 1; i++) {
                print(1);
                print(" ");
            }
            print(1);
            if (length > num)
                print(" ");
            for (int i = 1; i < length - num; i++) {
                print(2);
                print(" ");
            }
            print(2);
        }
        else {
            for (int i = 0; i < num; i++) {
                if (i % 2 == 0)
                    print(1);
                else
                    print(sum - 1);
                print(" ");
            }
            if (num % 2 == 0)
                print(1);
            else
                print(sum - 1);
            if (length > num + 1) {
                print(" ");
            
                for (int i = 1; i < length - num - 1; i++) {
                    print(sum != 1000000000 ? sum + 1 : 2);
                    print(" ");
                }
                print(sum != 1000000000 ? sum + 1 : 2);
            }
        }
        flush();
    }

    // 入出力関連
    static final BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    static final PrintWriter pw = new PrintWriter(System.out);

    enum Delimiter {
        NONE(""), SPACE(" "), DOT("\\."), COMMA(",");

        private String regex;

        private Delimiter(String regex) {
            this.regex = regex;
        }

        public String getRegex() {
            return regex;
        }
    }

    static String receive() throws IOException {
        return br.readLine();
    }

    static int receiveInt() throws IOException {
        return Integer.parseInt(br.readLine());
    }

    static char receiveChar() throws IOException {
        return br.readLine().charAt(0);
    }

    static char[] receiveCharArray() throws IOException {
        return br.readLine().toCharArray();
    }

    static int[] receiveIntArray(Delimiter delimiter) throws IOException {
        return Stream.of(br.readLine().split(delimiter.getRegex())).mapToInt(Integer::parseInt).toArray();
    }

    static String[] receiveStringArray(Delimiter delimiter) throws IOException {
        return Stream.of(br.readLine().split(delimiter.getRegex())).toArray(String[]::new);
    }

    static void print(Object obj) {
        pw.print(obj);
    }

    static void println(Object obj) {
        pw.println(obj);
    }

    static void flush() {
        pw.flush();
    }
}
