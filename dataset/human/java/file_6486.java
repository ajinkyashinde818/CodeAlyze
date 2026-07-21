import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        int K = sc.nextInt();
        int S = sc.nextInt();
        int[] sMinusZ = new int[K + 1];
        for (int i=0; i<=K; i++) {
            sMinusZ[i] = S - i;
        }
        Arrays.sort(sMinusZ);

        int sum = 0;
        for (int i=0; i<=K; i++) {
            for (int j=0; j<=K; j++) {
                if (Arrays.binarySearch(sMinusZ, i+j) >= 0) {
                    sum++;
                }
            }
        }

        System.out.println(sum);
    }
}
