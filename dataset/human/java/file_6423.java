import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int k = in.nextInt();
        int s = in.nextInt();

        int count = 0;
        for (int i = 0; i <= k; i++) {
            int diff = s - i;
            for (int j = 0; j <= k; j++) {
                int diff2 = diff - j;
                if (diff2 >= 0 && diff2 <= k) {
                    count++;
                }
//                for (int l = 0; l <= k; l++) {
//                    if (diff2 - l == 0) {
//                        count++;
//                    }
//                }
            }
        }
        System.out.println(count);
    }

}
