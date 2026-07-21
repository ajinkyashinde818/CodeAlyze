import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner stdIn = new Scanner(System.in);
        int N = stdIn.nextInt();
        int R = stdIn.nextInt();
        stdIn.close();

        int X = 0;
        if (N >= 10) {
            X = R;
        } else {
            X = R + 100 * (10 - N);
        }
       
        System.out.println(X);
    }
}
