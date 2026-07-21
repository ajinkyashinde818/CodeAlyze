import java.util.*;

public class Main {

    Scanner sc = new Scanner(System.in);

    public static void main(String[] args) {
        new Main().run();
    }

    void run() {

        int a = sc.nextInt();
        int b = sc.nextInt();
        int c = sc.nextInt();


        if (a >= c) {
            System.out.println(c + b);
        } else {
            int diff = c - a;
            if (b + 2 <= diff) {
                System.out.println(a + b + b + 1);
            } else {
                System.out.println(c + b);
            }
        }


    }


}
