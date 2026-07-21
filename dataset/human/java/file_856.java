import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
    	int k = sc.nextInt();

        if (10>n) {
        	int r = 100 * (10 - n);
        	k = r + k;
        }
    	System.out.println(k);
    }
}
