import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.HashMap;
import java.util.Map;

public class Main {

  static long n;
  static Map<Long, Long> pri;
  static long ans;

  public static void main(String[] args) throws Exception {

    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter out = new PrintWriter(System.out);

    String[] in = br.readLine().split(" ");
    n = Long.parseLong(in[0]);

    br.close();

    pri = new HashMap<>();

    long tmp = n;

    for (long i = 2; i * i <= n; i++) {
      long divCnt = 0;
      while(tmp % i == 0){
        divCnt++;
        tmp /= i;
      }

      if(divCnt != 0){
        pri.put(i, divCnt);
      }
    }

    if(tmp != 1L){
      pri.put(tmp, 1L);
    }

    ans = 0;

    for (Map.Entry<Long, Long> e : pri.entrySet()) {
      long t = e.getValue();
      long itr = 1;
      while(t >= itr){
        t -= itr;
        ans++;
        itr++;
      }
    }

    out.println(ans);

    out.flush();
  }
}
