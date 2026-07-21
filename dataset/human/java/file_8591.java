import java.util.*;

import javax.swing.text.AbstractDocument.BranchElement;

import com.sun.org.apache.xpath.internal.SourceTree;

public class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int k = sc.nextInt();
        Set<Integer> ans1 = new TreeSet<>();
        for (int i = 1; i <= a; i++) {
            if (a % i == 0) {
                ans1.add(i);
            }
        }
        Set<Integer> ans2 = new TreeSet<>();
        for (int i = 1; i <= b; i++) {
            if (b % i == 0) {
                ans2.add(i);
            }
        }
        List<Integer> result = new ArrayList<>();
        for (Integer val1 : ans1) {
            for (Integer val2 : ans2) {
                if (val1 == val2) {
                    result.add(val1);
                }
                if (val1 <= val2) {
                    break;
                }
            }
        }
        System.out.println(result.get(result.size() - k));
    }
}
