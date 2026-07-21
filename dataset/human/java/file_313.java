import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);

        int N = sc.nextInt();
        int[] AN = new int[N];
        int[] AN2 = new int[N];
        int changeCount = 0;
        int min = 2147483647;
        long S = 0;

        for (int i = 0; i < N; i++) {

            AN[i] = sc.nextInt();

            if(AN[i] < 0) {

                AN2[i] = -AN[i];
                changeCount++;
            } else {

                AN2[i] = AN[i];
            }

            min = (AN2[i] < min) ? AN2[i] : min;
        }

        if (changeCount % 2 == 0) {

            for (int i = 0; i < N; i++) {

                S += AN2[i];
            }
            System.out.println(S);
        } else {

            for (int i = 0; i < N; i++) {

                S += AN2[i];
            }
            System.out.println(S-min*2);
        }
        sc.close();
    }

}
