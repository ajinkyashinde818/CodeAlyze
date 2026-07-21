import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

    public static void main(String args[]) {

        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        List<Integer> a = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            a.add(sc.nextInt());
        }
        List<Integer> b = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            b.add(sc.nextInt());
        }
        List<Integer> c = new ArrayList<>();
        for (int i = 0; i < n - 1; i++) {
            c.add(sc.nextInt());
        }

        int result = 0;
        int preIndex = -2;
        for (int i = 0; i < n; i++) {
            int index = a.get(i) - 1;
            result += b.get(index);
            if (preIndex == index - 1) {
                result += c.get(preIndex);
            }
            preIndex = index;
        }

        System.out.println(result);
    }
}
