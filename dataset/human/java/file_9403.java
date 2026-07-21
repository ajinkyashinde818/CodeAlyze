import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        boolean isThree = false;
        int count = 0;
        int d1,d2;
        for (int i=0; i<n; i++) {
            d1 = sc.nextInt();
            d2 = sc.nextInt();
            if (d1 == d2) {
                count++;
                if (count == 3) {
                    isThree = true;
                }
            } else {
                count = 0;
            }
        }
        System.out.print(isThree ? "Yes" : "No");
    }
}
