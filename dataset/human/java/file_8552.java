import java.util.ArrayList;
import java.util.Collections;
import java.util.List;
import java.util.Scanner;
 
public class Main {
    public static void main(String args[]) {
        final Scanner lineScanner = new Scanner(System.in);
        final int A = lineScanner.nextInt();
        final int B = lineScanner.nextInt();
        final int needIndex = lineScanner.nextInt();
 
        List<Integer> numList = new ArrayList<>();
        for (int i = 1; i <= A && i <= B; i++) {
            if (A % i == 0 && B % i == 0) {
                numList.add(i);
            }
        }
        Collections.sort(numList, Collections.reverseOrder());
        System.out.println(numList.get(needIndex - 1));
    }
}
