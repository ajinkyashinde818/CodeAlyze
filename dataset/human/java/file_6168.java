import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int k = sc.nextInt();
        int s = sc.nextInt();

        int result = 0;
        for (int i = 0; i < s + 1; i++) {
            int x = i;
            for (int j = 0; j < s + 1 - i; j++) {
                int y = j;
                int z = s - x - y;
                if (x > k || y > k || z > k) {
                    continue;
                }
                result++;
            }
        }
        System.out.println(result);
    }

}
