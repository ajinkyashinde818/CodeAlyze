import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.next());
        int m = Integer.parseInt(sc.next());
        String[] na = new String[n];
        String[] ma = new String[m];
        for (int i = 0; i < n; i++) {
            na[i] = sc.next();
        }
        for (int i = 0; i < m; i++) {
            ma[i] = sc.next();
        }
        boolean ans = false;
        for (int i = 0; i <= n - m; i++) {
            int temp = i;
            List<Integer> list = new ArrayList<>();
            for (int j = 0; j <= m; j++) {
                if (j == 0) {
                    int idx = 0;
                    int tempIdx = 0;
                    while (idx != -1) {
                        idx = na[temp].indexOf(ma[j], tempIdx);
                        if (idx != -1) {
                            list.add(idx);
                            tempIdx = idx + 1;
                        }
                    }
                } else {
                    if (list.size() == 0) {
                        break;
                    } else {
                        temp++;
                        if (temp - i >= m) {
                            ans = true;
                            break;
                        }
                        for (int k = list.size() - 1; k >= 0; k--) {
                            int a = list.get(k);
                            if (!na[temp].substring(a, a + m).equals(ma[j])) {
                                list.remove(k);
                            }
                        }
                    }
                }
            }
            if (ans) {
                break;
            }
        }
        System.out.println(ans ? "Yes" : "No");
    }
}
