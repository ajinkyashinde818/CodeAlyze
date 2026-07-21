import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int k = sc.nextInt();
    int n = sc.nextInt();
    int max = 0;
    ArrayList<Integer> list = new ArrayList<>();
    for (int i = 0; i < n; i++) {
      list.add(sc.nextInt());
    }
    list.add(k+list.get(0));
    for (int i = 0; i < n; i++) {
      max = Math.max(max, list.get(i+1)-list.get(i));
    }
    System.out.println(k-max);
    sc.close();
  }
}
