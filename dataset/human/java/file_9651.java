import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        int N = scanner.nextInt();
        List<int[]> examples = new ArrayList<>();
        for (int i = 0; i < N; i++) {
            int[] ints = new int[2];
            ints[0] = scanner.nextInt();
            ints[1] = scanner.nextInt();
            examples.add(ints);
        }
        judge(examples);
    }

    private static void judge(List<int[]> examples) {
        int count = 0;
        for (int[] item: examples) {
            if (item[0] == item[1]) {
                count++;
            } else {
                count = 0;
            }
            if (count == 3) {
                System.out.println("Yes");
                return;
            }
        }
        System.out.println("No");
    }
}
