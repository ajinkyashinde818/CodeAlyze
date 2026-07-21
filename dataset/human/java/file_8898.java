import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;

/**
 *
 * @author kouki
 */
public class Main{

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int A = sc.nextInt();
        int B = sc.nextInt();
        int K = sc.nextInt();
        List<Integer> list = new ArrayList<>();
        if (A > B) {
            for (int i = 1; i < B+1; i++) {
                if (B % i == 0 && A % i == 0) {
                    list.add(i);
                }
            }
        } else if (B > A) {
            for (int i = 1; i < A+1; i++) {
                if (A % i == 0 && B % i == 0) {
                    list.add(i);
                }
            }
        } else if (A == B) {
            for (int i = 1; i < A+1; i++) {
                if (A % i == 0 && B % i == 0) {
                    list.add(i);
                }
            }
        } else {
        }
        Collections.sort(list, Collections.reverseOrder());
        System.out.println(list.get(K-1));
    }

}
