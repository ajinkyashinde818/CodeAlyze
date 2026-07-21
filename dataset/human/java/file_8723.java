import java.util.*;

public class Main {
  public static void main(String[] args) {
    Scanner sc = new Scanner(System.in);

    int A = sc.nextInt();
    int B = sc.nextInt();
    int K = sc.nextInt() - 1;

    List<Integer> divisorA = cul(A);
    List<Integer> divisorB = cul(B);

    List<Integer> common = new ArrayList<>();

    for(Integer a : divisorA){
      if(divisorB.contains(a)){
        common.add(a);
      }
    }

    Collections.sort(common, Collections.reverseOrder());

    System.out.println(common.get(K));

  }

  public static List<Integer> cul(int number) {
    List<Integer> divisor = new ArrayList<>();

    for (int i = 1; i <= number ; i++ ) {
      if (number%i == 0) {
        divisor.add(i);
      }
    }

    return divisor;
  }
}
