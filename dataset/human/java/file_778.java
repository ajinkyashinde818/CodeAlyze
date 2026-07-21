import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int numOfAttend = sc.nextInt();
        int outerRate = sc.nextInt();
        int N = 10;

        int innerRate = numOfAttend <= N ? outerRate + (N - numOfAttend) * 100 : outerRate;
        System.out.println(innerRate);
        sc.close();

    }
}
