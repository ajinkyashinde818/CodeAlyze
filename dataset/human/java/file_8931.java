import java.util.*;
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int k = sc.nextInt();
        int number = 0;
        int result = Math.min(a, b);
        while (number < k) {
            if (a % result ==  0 && b % result == 0) {
                number++;
            }
            result--;
        }
        System.out.println(result + 1);
        sc.close();
    }
}
