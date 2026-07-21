import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
	// write your code here

        int count = 0;

        Scanner scanner = new Scanner(System.in);
        int food = scanner.nextInt();
        int[] A = new int[food], B = new int[food], C = new int[food - 1];
        for (int i = 0; i < food; i++) A[i] = scanner.nextInt();
        for (int i = 0; i < food; i++) B[i] = scanner.nextInt();
        for (int i = 0; i < food - 1; i++) C[i] = scanner.nextInt();

        int lastPoint = -1;

        for (int i = 0; i < food; i++) {
            if (lastPoint != -1 && A[lastPoint] + 1 == A[i]) count += C[A[i] - 2];
            count += B[A[i] - 1];
            lastPoint = i;
        }

        System.out.println(count);
    }
}
