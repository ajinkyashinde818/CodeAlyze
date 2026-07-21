import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        // Your code here!
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int start = 1;
        int goal = n;
        int m = sc.nextInt();
        Set<Integer> checkPoint1 = new HashSet<Integer>();
        Set<Integer> checkPoint2 = new HashSet<Integer>();
        
        boolean clear = false;
        while (m-- > 0) {
            int p = sc.nextInt();
            int q = sc.nextInt();
            
            if (p == start) {
                if (checkPoint2.contains(q)) {
                    clear = true;
                    break;
                }
                checkPoint1.add(q);
            } else if (q == goal) {
                if (checkPoint1.contains(p)) {
                    clear = true;
                    break;
                }
                checkPoint2.add(p);
            }
        }
        
        if (clear) {
            System.out.println("POSSIBLE");
        } else {
            System.out.println("IMPOSSIBLE");
        }
    }
}
