import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int N = Integer.parseInt(in.nextLine());
        int countDoublets = 0;
        boolean threeConsecutive = false;
        for (int i = 0 ; !threeConsecutive && i < N; i++) {
            String[] read = in.nextLine().split(" ");
            int d1 = Integer.parseInt(read[0]), d2 = Integer.parseInt(read[1]);
            if (d1 == d2) {
                countDoublets++;
                if (countDoublets == 3) {
                    System.out.println("Yes");
                    threeConsecutive = true;
                }
            } else {
                countDoublets = 0;
            }
        }

        if (!threeConsecutive)
            System.out.println("No");

    }
}
