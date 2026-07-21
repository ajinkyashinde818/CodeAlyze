import java.util.*;

public class Main {
  public static void main(String[]args) {
    Scanner s = new Scanner(System.in);
    int a = s.nextInt(), b = s.nextInt(), c = s.nextInt();
    List<Integer> list = new ArrayList<>();
    for (int i = 1; i <= Math.min(a, b) ; ++i) {
      if (a % i == 0 && b % i == 0) {
	 list.add(i);
      }
    }
    System.out.println(list.get(list.size() - c));
  }  
}
