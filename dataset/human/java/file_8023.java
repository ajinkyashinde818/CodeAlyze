import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        long a = scan.nextInt();
        long b = scan.nextInt();
        long max = Math.max(a, b);
        long temp = a * b;
        long ans = 0;
        for(long i = max; i <= temp; i += max) {
        	if(i % a == 0 && i % b == 0) {
        		ans = i;
        		break;
        	}
        }
        System.out.println(ans);
    }
}
