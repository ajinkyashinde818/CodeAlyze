import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String str = scan.nextLine();
        scan.close();

        String[] ks = str.split(" ");

        int n = 0;

        int k = Integer.parseInt(ks[0]);
        int s = Integer.parseInt(ks[1]);

        for (int x = 0; x <= k; x++) {
            for (int y = 0; y <= k; y++) {
                int z = s - x - y;
                if (0 <= z && z <= k) {
                    //System.out.println(x + ", " + y + ", " + z);
                    n++;
                }
            }
        }

        System.out.println(n);

    }
}
