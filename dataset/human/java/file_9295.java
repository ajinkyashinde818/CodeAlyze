import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.next());
        int count = 0;
        String ans = "No";
        for (int i = 0; i < n; i++) {
            count = sc.next().equals(sc.next()) ? count + 1 : 0;
            if(count == 3) {
                ans = "Yes";
            }
        }

        System.out.println(ans);
    }
}
