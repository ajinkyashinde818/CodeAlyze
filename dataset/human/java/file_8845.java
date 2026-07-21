import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int A = Integer.parseInt(sc.next());
        int B = Integer.parseInt(sc.next());
        int K = Integer.parseInt(sc.next());
        int len = (A < B) ? A : B;
        List r = new ArrayList<Integer>();
        for (int i = 1; i <= len; i++) {
            if (A % i == 0 && B % i == 0) r.add(i);
        }
        System.out.println(r.get(r.size()-K));
    }
}
