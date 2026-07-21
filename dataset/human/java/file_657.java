import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Integer N = sc.nextInt();
        Integer R = sc.nextInt();
        if(N>=10) {
            System.out.println(R);
        } else {
            System.out.println(R + (10-N) * 100);
        }
    }
}
