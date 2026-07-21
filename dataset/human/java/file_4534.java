import java.util.Scanner;

public class Main {

    private static Scanner sc = new Scanner(System.in);
    public static void main(String[] args) {

        int A = sc.nextInt();
        int B = sc.nextInt();
        int C = sc.nextInt();
        int maxC = C <= (A + B + 1) ? C :(A + B+1);
        int max = maxC + B;

        System.out.println(max);
    }

}
