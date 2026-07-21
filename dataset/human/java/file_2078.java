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

        // Start: int型の整数N Mを取得する
        // // N M 形式
        long N = in.longNext();
        // int M = in.intNext();

        // for (long i = 2L; i < N; i *= 2) {
        //   if (
        // }

        if (N == 1) {
          out.println(0);
          out.close();
          return;
        }
        if (isPrimeLong(N)) {
          out.println(1);
          out.close();
          return;
        }
        ArrayList<Long> primes = new ArrayList<>();
        long prime = N;
        long sqrt = (long) Math.sqrt(N) + 1;
        ArrayList<Integer> primeOccurence = new ArrayList<>();
        for (long i = 2L; i < sqrt; i++) {
          if (prime % i == 0L) {
            int count = 0;
            while (prime % i == 0L) {
              prime /= i;
              count++;
            }
            primeOccurence.add(count);
          }

          // if (n != 0L) {
          //   for (long j = n; j > 0L; j--) {
          //     primes.add(i);
          //   }
          // }
        }

		    if (prime != 1 || primeOccurence.size() == 0)
		    	primeOccurence.add(1);

        // ArrayList<Long> uniqPrimes = new ArrayList<>();
        // for (long p : primes) {
        //   if(!uniqPrimes.contains(p))
        //       uniqPrimes.add(p);
        // }

        // ArrayList<Integer> primeOccurence = new ArrayList<>();
        // for (long p : uniqPrimes) {
        //   primeOccurence.add(Collections.frequency(primes, p));
        // }

        // int counter = 0;
        // for (int num : primeOccurence) {
        //   for (int i = 0; i < num; i++) {
        //     if (i + i + 1 <= num) {
        //       counter++;
        //     }
        //   }
        // }
        // result.append(counter);

        // ArrayList<int> numPrimes = new ArrayList<>();
        // long prevP = -1;
        // for (int i; i < primes.size(); i++) {
        //   long p = primes.get(i);
        //   if (prevP == p) {
        //     numPrimes.set(i, numPrimes.get(i)++);
        //   } else {
        //     numPrimes.set(i, numPrimes.get(i)++);
        //   }
        //   prevP = p;
        // }


        //for(long p : primes) {
        //  out.println(p);
        //}

        int ans = 0;
        for (long p : primeOccurence) {
          long used = 0;
          while (p > used) {
            ans++;
            used++;
            p -= used;
          }
        }
        result.append(ans);
        // ArrayList<Long> memo = new ArrayList<>();
        // int count = 0;

        // long prev = 1;

        // int i = 0;
        // while (i < primes.size()) {
        //   long p = primes.get(i);

        //   while (memo.contains(p)) {
        //     i++;
        //     if (i == primes.size()) break;
        //     p *= primes.get(i);
        //   }

        //   if (!memo.contains(p) && i < primes.size()) {
        //     memo.add(p);
        //     count++;
        //     i++;
        //   }
        // }
        // result.append(count);

        //[補足]
        // N M
        // A B 形式だと
        // int N = in.intNext();
        // int M = in.intNext();
        // int A = in.intNext();
        // int B = in.intNext();
        // End: int型の整数N Mを取得する

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

        // Start: forEach文
        // for (int elem: elements) {
        // }
        // Start: forEach文

        out.println(result);

        out.close();
    }

    // 素数判定。
    public static boolean isPrime(int N) {
      if (N == 1) return false;
      for (int i = 2; i * i <= N; ++i) {
        if (N % i == 0) return false;
      }
      return true;
    }

    public static boolean isPrimeLong(Long N) {
      if (N == 1L) return false;
      for (long i = 2L; i * i <= N; ++i) {
        if (N % i == 0L) return false;
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
