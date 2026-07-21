import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();
        int r = in.nextInt();
        int result = r;
        if(n<10) {
            result = r + 100 * (10 - n);
        }
        System.out.println(result);
    }
}
