import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        if (a > 10) {
          System.out.println(b);
        } else {
          System.out.println(b + (100 * (10 - a)));
        }
    }
}
