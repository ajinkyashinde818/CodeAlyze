import java.util.Scanner;

public class Main {
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long N = sc.nextLong();
        long ans = 0;
        for (int i = 2; i < Math.sqrt(N); i++) {
            int count = 0;
            while (true) {
                if (N%i == 0) {
                    N /= i;
                    count++;
                } else {
                    break;
                }
            }
            int index = 1;
            while (true) {
                count -= index;
                if (0 <= count) {
                    ans++;
                } else {
                    break;
                }
                index++;
            }
        }
        System.out.println(N == 1 ? ans : ans+1);
    }
}
