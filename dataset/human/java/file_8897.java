import java.util.*;

class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);
    int A = sc.nextInt();
    int B = sc.nextInt();
    int K = sc.nextInt();
    ArrayList<Integer> ar = new ArrayList<>();
    for (int i = 1; i <= Math.min(A, B); i++) {
      if (A % i == 0 && B % i == 0)
        ar.add(i);
    }
    System.out.println(ar.get(ar.size() - K));
  }
}
