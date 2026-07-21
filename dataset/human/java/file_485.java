import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int N;
        int R;

        int temp1;
        int temp2;

        N = sc.nextInt();
        R = sc.nextInt();

        temp1 = 100 * (10-N) + R;
        temp2 = R;

        if( N < 10) {
            System.out.println(temp1);
        }
        else if( N >= 10) {
            System.out.println(R);
        }
    }
}
