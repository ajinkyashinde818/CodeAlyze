import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        try (Scanner scanner = new Scanner(System.in);) {
            int n = scanner.nextInt();
            int cnt = 0;
            String ans = "No";

            for(int i = 0; i < n; i++) {
                if(scanner.nextInt() == scanner.nextInt()) {
                    cnt++;
                    if(cnt >= 3) {
                        ans = "Yes";
                        System.out.println(ans);
                        return;
                    }
                } else {
                    cnt = 0;
                }
            }
            
            System.out.println(ans);
        } catch (Exception e) {
            e.printStackTrace();
        }
    }
}
