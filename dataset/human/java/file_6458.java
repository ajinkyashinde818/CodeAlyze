import java.util.Scanner;

public class Main {
    public static void main(String args[]) {
        try (Scanner in = new Scanner(System.in)) {
            int K = in.nextInt();
            int S = in.nextInt();
            int count = 0;
            for (int X = 0; X <= K; X++) {
                for (int Y = 0; Y <= K; Y++) {
                    int Z = S - (X + Y);
                    if (!(Z >= 0 && Z <= K)) {
                        continue;
                    }
                    count++;
                }
            }
            System.out.println(count);
        }
    }
}
