import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();

        long c = (long)a * b;

        int tmp;
        while(a % b != 0) {
            tmp = b;
            b = a % b;
            a = tmp;
        }

        System.out.println(c / b);

    }
}
