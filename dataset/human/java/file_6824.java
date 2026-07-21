import java.util.*;
import java.util.stream.Collectors;

public class Main {

  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int N = sc.nextInt();
    int K = sc.nextInt();
    int max = 0;
    ArrayList<Integer> list = new ArrayList<Integer>();
    list.add(sc.nextInt());
    for (int i = 1; i < K; i++) {
      list.add(sc.nextInt());
      max = Math.max(max, list.get(i) - list.get(i - 1));
    }
    int last = (N - list.get(list.size() - 1)) + list.get(0);
    int ans = N - Math.max(max, last);
    System.out.println(ans);

  }
}
