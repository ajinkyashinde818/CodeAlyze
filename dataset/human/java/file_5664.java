import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int k = sc.nextInt();
        int s = sc.nextInt();
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < k; i++) {
            sb.append(s + " ");
        }
        int a = s % 2 == 0 ? 999_999_999 : 2;
        for (int i = 0; i < n-k; i++) {
            sb.append(a + " ");
        }
        sb.deleteCharAt(sb.length()-1);
        System.out.println(sb.toString());
        sc.close();

    }

}
