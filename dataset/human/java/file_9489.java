import java.util.*;

public class Main {
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int count = 0;
        boolean key = false;
        for (int i = 0; i < N; i++) {
            int D1 = sc.nextInt();
            int D2 = sc.nextInt();
            if (D1 == D2) {
                count++;
            } else {
                count = 0;
            }
            if (count == 3) {
                key = true;
            }
        }
        if (key) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
}
