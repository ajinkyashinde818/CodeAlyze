import java.util.*;

public class Main {

    public static void main(String[] args) {

        Scanner in = new Scanner(System.in);

        int A = in.nextInt();
        int B = in.nextInt();
        int C = in.nextInt();

        int totalAnti = A + B;

        int res = B + Math.min(totalAnti, C) + (totalAnti < C ? 1 : 0);

        System.out.print(res);

    }

}
