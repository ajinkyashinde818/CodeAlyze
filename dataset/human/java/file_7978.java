import java.util.*;

public class Main {
    public static void main(String args[]) throws Exception {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();

        long product = (long)a * b;

        System.out.println(product / gcd(a, b));
    }

    private static int gcd(int a, int b) {
    	if(b == 0)
    		return a;
    	return gcd(b, a % b);
    }
}
