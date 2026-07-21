import java.util.Scanner;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        long max = Math.max(a, b);
        long min = Math.min(a, b);
        int i = 1;
        long result = 0;
        while (true) {
            if ((max * i) % min == 0) {
                result = max * i;
                break;
            }
            i++;
        }
        System.out.println(result);
        sc.close();
    }
}
