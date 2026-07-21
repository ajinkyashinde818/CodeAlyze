import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner Input = new Scanner(System.in);
        int K = Input.nextInt();
        int S = Input.nextInt();
        int Counter = 0;
        for (int X = 0; X <= K; X++) {
            for (int Y = 0; Y <= K; Y++) {

                if (0 <= S - (X + Y) && S - (X + Y) <= K) {
                    Counter++;
                }
            }
        }
        System.out.println(Counter);
    }
}
