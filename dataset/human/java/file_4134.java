import java.util.Scanner;
public class Main{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int kind = sc.nextInt();
        int[] a = new int[kind];
        int[] b = new int[kind];
        int[] c = new int[kind];
        int sum = 0;
        for (int i = 0; i < kind; i++) {
            a[i] = sc.nextInt();
        }
        for (int i = 0; i < kind; i++) {
            b[i] = sc.nextInt();
            sum += b[i];
        }
        for (int i = 0; i < kind - 1; i++) {
            c[i] = sc.nextInt();
        }
        for (int i = 0; i < kind - 1; i++) {
            if (a[i + 1] - a[i] == 1) {
                sum += c[a[i]-1];
            }
        }
        System.out.println(sum);
    }
}
