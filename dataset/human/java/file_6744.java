import java.util.*;
import java.io.*;
 
public class Main {
  public static void main(String[] args) throws Exception{
    Scanner sc = new Scanner(System.in);
    int k = sc.nextInt();
    int n = sc.nextInt();
    int[] num = new int[n];
    for(int i = 0; i < n; ++i) {
      num[i] = sc.nextInt();
    }
    new Solution(n, k, num);
  }
}

class Solution {
  public Solution(int n, int k, int[] num) {
    int res = 0;
    Arrays.sort(num);
    for(int i = 1; i < n; ++i) {
      if(res < num[i] - num[i - 1]) res = num[i] - num[i - 1];
    }
    if(res < k + num[0] - num[n - 1]) res = k + num[0] - num[n - 1];
    System.out.println(k - res);
      // System.out.println(res);
  }
}

class Scanner {
  StringTokenizer st;
  BufferedReader br;

  public Scanner(InputStream system) {
    br = new BufferedReader(new InputStreamReader(system));
  }

  public Scanner(String file) throws Exception {
    br = new BufferedReader(new FileReader(file));
  }

  public String next() throws IOException {
    while (st == null || !st.hasMoreTokens())
      st = new StringTokenizer(br.readLine());
    return st.nextToken();
  }

  public String nextLine() throws IOException {
    return br.readLine();
  }

  public int nextInt() throws IOException {
    return Integer.parseInt(next());
  }

  public double nextDouble() throws IOException {
    return Double.parseDouble(next());
  }

  public char nextChar() throws IOException {
    return next().charAt(0);
  }

  public Long nextLong() throws IOException {
    return Long.parseLong(next());
  }

  public int[] nextArrInt(int n) throws IOException {
    int[] a = new int[n];
    for (int i = 0; i < n; i++)
      a[i] = nextInt();
    return a;
  }

  public long[] nextArrLong(int n) throws IOException {
    long[] a = new long[n];
    for (int i = 0; i < n; i++)
      a[i] = nextInt();
    return a;
  }

  public boolean ready() throws IOException {
    return br.ready();
  }

  public void waitForInput() throws InterruptedException {
    Thread.sleep(3000);
  }
}
