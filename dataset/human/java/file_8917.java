import java.util.*;

public class Main {
	public static void main(String[] args) {
    	Scanner sc = new Scanner(System.in);
      	int number_a, number_b, number_k, i, count = 0;
      	number_a = Integer.parseInt(sc.next());
      	number_b = Integer.parseInt(sc.next());
      	number_k = Integer.parseInt(sc.next());
      for(i = Math.min(number_a, number_b); i > 0; i--) {
        if(number_a % i == 0 && number_b % i == 0) count++;
        if(count == number_k) break;
      }
      System.out.println(i);
    }
}
