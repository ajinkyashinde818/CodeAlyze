import java.util.Scanner;

public class Main {
    public static void main(String[] args) {

        Scanner scanner = new Scanner(System.in);
        String[] line = scanner.nextLine().split(" ");

        int k = Integer.parseInt(line[0]);
        int s = Integer.parseInt(line[1]);

        int count = 0;
        for (int x = 0; x <= k; x++) {
            for (int y = 0; y <= k; y++) {
                int z = s - x - y;
                if (0 <= z && z <= k) count++;
            }
        }

        System.out.println(count);
    }

}
