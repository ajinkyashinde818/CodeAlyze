import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        final int n = Integer.parseInt(sc.next());
        final int r = Integer.parseInt(sc.next());
        int answer = 0;
        if (n >= 10) {
            answer = r;
        } else {
            answer = r + (100 * (10 - n));
        }
        System.out.println(answer);
        sc.close();
    }
}
