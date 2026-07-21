import java.io.*;

public class Main {
    public static void main(String[] args) throws Exception {
        // 入力
        MyScanner sc = new MyScanner(System.in);
        String S = sc.nextString();

        // 初期化

        // 主処理
        String tmp = S;
        tmp = tmp.replaceAll("eraser", "");
        tmp = tmp.replaceAll("erase", "");
        tmp = tmp.replaceAll("dreamer", "");
        tmp = tmp.replaceAll("dream", "");
        String ans = "".equals(tmp) ? "YES" : "NO";

        // 出力
        System.out.println(ans);
    }

    static class MyScanner {
        BufferedReader br;
        // 標準入力から入力値を取得
        MyScanner(InputStream in) {
            br = new BufferedReader(new InputStreamReader(in));
        }
        // 標準入力を文字列で取得
        public String nextString() throws IOException {
            return br.readLine();
        }
        // 標準入力を文字列の配列で取得
        public String[] nextStringArray() throws IOException {
            return nextString().split(" ");
        }
        // 標準入力を数値で取得
        public int nextInt() throws IOException {
            return Integer.parseInt(nextString());
        }
        // 標準入力を数値の配列で取得
        public int[] nextIntArray() throws IOException {
            String[] strArr = nextStringArray();
            int[] intArr = new int[strArr.length];
            for(int i = 0; i < strArr.length; i++) {
                intArr[i] = Integer.parseInt(strArr[i]);
            }
            return intArr;
        }
    }

}
