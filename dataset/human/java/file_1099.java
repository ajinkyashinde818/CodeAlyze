import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.stream.Stream;

public class Main {

  public static void main(String[] args) throws Exception {
    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    int n = Integer.parseInt(br.readLine());
    int[] a = Stream.of(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
    int[] b = Stream.of(br.readLine().split(" ")).mapToInt(Integer::parseInt).toArray();
    br.close();

    int[] a_cnt = new int[n + 1];
    int[] b_cnt = new int[n + 1];
    int[] c = new int[n + 1];
    int[] d = new int[n + 1];
    for(int i = 0; i < n; i++){
      a_cnt[a[i]]++;
      b_cnt[b[i]]++;
    }

    int max_d = 0;
    String[] array = new String[n];
    for(int i = 1; i <= n; i++){
      if(a_cnt[i] + b_cnt[i] > n){
        System.out.println("No");
        return;
      }
      c[i] = c[i - 1] + a_cnt[i];
      d[i] = d[i - 1] + b_cnt[i];
      max_d = Math.max(max_d, c[i] - d[i - 1]);
    }
    System.out.println("Yes");
    for(int i = 0; i < n; i++){
      array[i] = String.valueOf(b[( i + n - max_d) % n]);
    }
    System.out.println(String.join(" ", array));
  }
}
