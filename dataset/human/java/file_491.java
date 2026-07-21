import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.next());
        int r = Integer.parseInt(sc.next());
        if(n < 10) {
            r += 100 * (10-n);
        }
        System.out.println(r);
    }
}
