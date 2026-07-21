import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.PrintWriter;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;
import java.util.stream.Collectors;

public class Main {

  static int n, ans;
  static long k;
  static List<Integer> a, step;

  public static void main(String[] args) throws Exception {

    BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
    PrintWriter out = new PrintWriter(System.out);

    String[] in = br.readLine().split(" ");
    n = Integer.parseInt(in[0]);
    k = Long.parseLong(in[1]);

    in = br.readLine().split(" ");
    a = Arrays.stream(in).map(Integer::parseInt).collect(Collectors.toList());

    br.close();


    step = new ArrayList<>();
    for (int i = 0; i < n; i++) {
      step.add(0);
    }

    int loop = 1, city = a.get(0);

    while (step.get(city-1) == 0 && city != 1) {
      step.set(city - 1, loop++);
      city = a.get(city - 1);
    }

    int period = loop - step.get(city-1);

    if (k > step.get(city-1)) {
      k = (k - step.get(city-1)) % period + step.get(city-1);
    }

    city = 1;

    for (int i = 0; i < k; i++) {
      city = a.get(city - 1);
    }

    out.println(city);

    out.flush();
  }
}
