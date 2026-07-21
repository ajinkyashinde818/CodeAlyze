import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[] p = new int[n];
        for (int i = 0; i < n; i++) {
            p[i] = sc.nextInt();
        }
        int[] bunpu = new int[110];
        for (int i = 0; i < n; i++) {
            bunpu[p[i]]++;
        }
        for (int i = 105; i >= 0; i--) {
            bunpu[i] += bunpu[i+1];
        }
        for (int i = 105; i > 0; i--) {
            if(bunpu[i] >= i) {
                System.out.println(i);
                return;
            }
        }
    }
}
