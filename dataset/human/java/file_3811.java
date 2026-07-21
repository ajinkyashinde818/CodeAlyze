import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.PriorityQueue;
import java.util.Queue;
import java.util.Scanner;
import java.util.Stack;
 
class Main {
 
    public static void main(String[] args) {
        new Main().compute();
    }
 
    void compute() {
        Scanner sc = new Scanner(System.in);
        String S = sc.next();
        List<Character> removedX = new ArrayList<>();
        boolean[] isX = new boolean[S.length()];
        for (int i = 0; i < S.length(); i++) {
            if (S.charAt(i) == 'x') {
                isX[i] = true;
            } else {
               removedX.add(S.charAt(i));
            }
        }
        for (int i = 0; i < removedX.size() / 2; i++) {
            if (removedX.get(i) != removedX.get(removedX.size() - i - 1)) {
                System.out.println(-1);
                return;
            }
        }
        int ans = 0;
        int head = 0;
        int foot = S.length() - 1;
        while (foot - head > 0) {
            if (isX[head] == isX[foot]) {
                head++;
                foot--;
            } else if (isX[head] && !isX[foot]) {
                head++;
                ans++;
            } else {
                foot--;
                ans++;
            }
        }
        System.out.println(ans);
    }
}
