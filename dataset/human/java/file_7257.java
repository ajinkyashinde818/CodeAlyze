import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scn = new Scanner(System.in);

        int k = scn.nextInt();
        int n = scn.nextInt();
        int[] array = new int[n];
        for (int i = 0; i < n; i++) {
            array[i] = scn.nextInt();
        }
        int max = array[0] + k - array[n - 1];

        for (int i = 1; i < n; i++) {
            max = Math.max(max, array[i] - array[i - 1]);
        }

        System.out.println(k - max);

    }
}
