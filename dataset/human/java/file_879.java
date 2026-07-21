import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int r = scanner.nextInt();

        if(n <= 10){
            int i = 100 * (10-n);
            System.out.println(r+i);
        } else {
            System.out.println(r);
        }
    }
}
