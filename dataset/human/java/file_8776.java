import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        StringBuilder sb = new StringBuilder();
        int a = in.nextInt();
        int b = in.nextInt();
        int k = in.nextInt();

        int count = 0;
        int x = a < b ? a : b;
        for (int i = 1; i <= x; i++) {
            if (a % i == 0 && b % i == 0) {
                sb.append(i + "_");
                count++;
            }
        }
        String ans = sb.toString();
        System.out.println(ans.split("_")[count-k]);
    }
}
