import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        int N, R;
        Scanner sc = new Scanner(System.in);
        N = sc.nextInt();
        R = sc.nextInt();
        System.out.println(R + (N < 10 ? (100*(10-N)) : 0));
    }
}
