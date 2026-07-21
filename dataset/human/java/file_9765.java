// This template is based on Mr. tonymontaro's template (https://atcoder.jp/users/tonymontaro).
import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;
import java.util.StringTokenizer;

// For flatten() required Java8
import java.util.stream.Stream;
import java.util.stream.IntStream;

import java.util.Queue;
import java.util.ArrayDeque;

import java.util.ArrayList;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.Collections;

public class Main {
    static PrintWriter out;
    static CF_Reader in;

    static int INTMAX = 2147483647;

    // Start: 大きな数
    // 10^20くらいまで
    // long a = 0;
    // End: 大きな数
    public static void main(String[] args) throws IOException {
        out = new PrintWriter(new OutputStreamWriter(System.out));
        in = new CF_Reader();
        StringBuilder result = new StringBuilder();

        int N = in.intNext();
        int M = in.intNext();
        int X = in.intNext();

        int[] C = new int[N];
        int[][] A = new int[N][M];

        for (int i = 0; i < N; i++) {
          C[i] = in.intNext();
          for (int j = 0; j < M; j++) {
            A[i][j] = in.intNext();
          }
        }

        String[] list2 = new String[N];
        for (int i = 0; i < N; i++) {
          list2[i] = String.valueOf(i);
        }

        List<String[]> comb = new ArrayList<String[]>();
        for (int i = 1; i <= N; i++) {
          List<String[]> res = combination(list2, i);
          comb.addAll(res);
        }

        int minimum = INTMAX;

        for (String[] cArr : comb) {
          List<List<Integer>> pickedBooks = new ArrayList<List<Integer>>();

          for (String c : cArr) {
            int i = Integer.valueOf(c);
            List<Integer> tmp = new ArrayList<Integer>();
            for (int j = 0; j < M; j++) {
              tmp.add(A[i][j]);
            }
            pickedBooks.add(tmp);
          }

          int[] goals = new int[M];
          for (int i = 0; i < pickedBooks.size(); i++) {
            for (int j = 0; j < M; j++) {
              goals[j] += pickedBooks.get(i).get(j);
            }
          }

          boolean isAchieved = true;
          for (int g : goals) {
            if (g < X) {
              isAchieved = false;
              break;
            }
          }

          int sum = 0;
          for (String c : cArr) {
            sum += C[Integer.valueOf(c)];
          }
          if (isAchieved) {
            if (minimum > sum) {
              minimum = sum;
            }
          }
        }

        if (minimum == INTMAX) {
          result.append(-1);
        } else {
          result.append(minimum);
        }



        // Start: int型の整数Nと配列Aを取得する
        // // N
        // // A1 A2 A3... AN 形式
        // int n = in.intNext();
        // int[] A = in.nextIntArray(n);
        // End: int型の整数Nと配列Aを取得する

        // Start: Char型の文字をInt型に変換する
        // Integer.parseInt(String.valueOf(charText))
        // End: Char型の文字をInt型に変換する

        // Start: 文字列を1文字ずつ出力する
        // String text = in.next();
        // char[] work = new char[text.length()];
        // for(int i = 0; i < text.length(); i++){
        //   work[i] = text.charAt(i); // Char型の文字
        //   out.println(work[i]);
        // }
        // End: 文字列を1文字ずつ出力する

        // Start: 配列の定義
        // int[] a = new int[N];
        // int[][] b = new int[N][M];
        // End: 配列の定義

        // Start: キューの定義
        // Queue<int[]> queue = new ArrayDeque<int[]>();
        // Start: キューの定義

        // Start: リストのリスト
        // @SuppressWarnings("unchecked")
        // List<Integer>[] adjacents = new ArrayList[N];
        // Start: リストのリスト

        out.println(result);

        out.close();
    }

    // 約数列挙
    // 使い方:
    // ArrayList<Integer> yakusuu = new ArrayList<>();
    // yakusuu = numeration(N);
    public static ArrayList<Integer> numeration (int N) {
        ArrayList<Integer> yakusuu = new ArrayList<>();

        ArrayList<Integer> leftYakusuu = new ArrayList<>();
        ArrayList<Integer> rightYakusuu = new ArrayList<>();

        for (int i = 1; i <= N/2; i++) {
          if (i > N / i) {
            break;
          }
          if (N % i == 0 && N / i != i) {
            leftYakusuu.add(i);
            rightYakusuu.add(N / i);
          }
          if (N % i == 0 && N / i == i) {
            leftYakusuu.add(i);
          }
        }
        yakusuu.addAll(leftYakusuu);
        Collections.reverse(rightYakusuu);
        yakusuu.addAll(rightYakusuu);
        return yakusuu;
    }

    public static ArrayList<Long> numeration (long N) {
        ArrayList<Long> yakusuu = new ArrayList<>();

        ArrayList<Long> leftYakusuu = new ArrayList<>();
        ArrayList<Long> rightYakusuu = new ArrayList<>();

        for (long i = 1; i <= N/2; i++) {
          if (i > N / i) {
            break;
          }
          if (N % i == 0 && N / i != i) {
            leftYakusuu.add(i);
            rightYakusuu.add(N / i);
          }
          if (N % i == 0 && N / i == i) {
            leftYakusuu.add(i);
          }
        }
        yakusuu.addAll(leftYakusuu);
        Collections.reverse(rightYakusuu);
        yakusuu.addAll(rightYakusuu);
        return yakusuu;
    }

    // 素数判定。
    public static boolean isPrime(int N) {
      if (N == 1) return false;
      for (int i = 2; i * i <= N; ++i) {
        if (N % i == 0) return false;
      }
      return true;
    }

    // 使い方
    // List<String> list = new ArrayList<String>();
    // permutation(list, "abc", "");
    // for (String str : list) {
    //   out.print(str + " ");
    // }
    // >> abc acb bac bca cab cba
    public static List<String> permutation(List<String> list, String target, String ans){
      if(target.length() <= 1) {
        list.add(ans + target);
      } else {
        for (int i = 0; i < target.length(); i++) {
          permutation(
            list,
            target.substring(0, i) + target.substring(i + 1),
            ans + target.charAt(i));
        }
      }
      return list;
    }

    // 使い方
    // String[] list2 = { "A", "B", "C", "D"};
    // List<String[]> res = combination(list2, 3);
    // for (String[] arr : res) {
    //   out.print("[");
    //   for (String a : arr) {
    //     out.print(a + ", ");
    //   }
    //   out.print("], ");
    // }
    // >> [A, B, C], [A, B, D], [A, C, D], [B, C, D]
    static List<String[]> combination(String[] data, int k) {
        List<String[]> result = new ArrayList<String[]>();
        combination(data, 0, new String[k], 0, result);
        return result;
    }

    static void combination(String[] data, int di, String[] comb, int ci, List<String[]> result) {
        if (ci == comb.length) {
            result.add(comb.clone());
            return;
        }
        for ( ; di <= data.length - (comb.length - ci); di++) {
            comb[ci] = data[di];
            combination(data, di + 1, comb, ci + 1, result);
        }
    }

    public static int[] flatten(int[][] arr) {
       return Stream.of(arr)
          .flatMapToInt(row -> IntStream.of(row))
          .toArray();
    }

    public static int maxIntValueFromArray(int[] array) {

        int intMax = array[0];

        for (int i = 1; i < array.length; i++ ) {
            if(intMax < array[i]) {
                intMax = array[i];
            }
        }
        return intMax;
    }

    public static int minIntValueFromArray(int[] array) {

        int intMin = array[0];

        for (int i = 1; i < array.length; i++ ) {
            if(intMin > array[i]) {
                intMin = array[i];
            }
        }
        return intMin;
    }

    public static boolean chmin(int[] dp, int i, int b) {
      if (dp[i] > b) {
        dp[i] = b;
        return true;
      }
      return false;
    }

    public static boolean chmax(int[] dp, int i, int b) {
      if (dp[i] < b) {
        dp[i] = b;
        return true;
      }
      return false;
    }

    static class CF_Reader {
        BufferedReader br;
        StringTokenizer st;

        public CF_Reader() throws IOException {
            br = new BufferedReader(new InputStreamReader(System.in));
        }

        String next() throws IOException {
            while (st == null || !st.hasMoreTokens())
                st = new StringTokenizer(br.readLine().trim());
            return st.nextToken();
        }

        long longNext() throws IOException {
            return Long.parseLong(next());
        }

        int intNext() throws IOException {
            return Integer.parseInt(next());
        }

        double doubleNext() throws IOException {
            return Double.parseDouble(next());
        }

        char charNext() throws IOException {
            return next().charAt(0);
        }

        public int[] nextIntArray(final int n) throws IOException {
            final int[] a = new int[n];
            for (int i = 0; i < n; i++)
                a[i] = intNext();
            return a;
        }

        public long[] nextLongArray(final int n) throws IOException {
            final long[] a = new long[n];
            for (int i = 0; i < n; i++)
                a[i] = longNext();
            return a;
        }

        String line() throws IOException {
            return br.readLine().trim();
        }
    }
}
