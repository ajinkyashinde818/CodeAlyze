import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        // ABC051B - Sum of Three Integers

        Scanner sc = new Scanner(System.in);

        int k = sc.nextInt();   // 2 <= k <= 2500
        int s = sc.nextInt();   // 0 <= s <= 3k

        Integer count = 0;
        for (int i = 0; i <= k; i++) {
            for (int j = 0; j <= k; j++) {
                int z = s - (i + j);
                if (0 <= z && z <= k) count++;
            }
        }
        
        System.out.println(count);
    }

}
