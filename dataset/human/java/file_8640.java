import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int a = Integer.parseInt(sc.next());
        int b = Integer.parseInt(sc.next());
        int num = Integer.parseInt(sc.next());
        int[] canDivided = new int[Math.max(a, b)];
        for (int i = 0; i < canDivided.length; i++) {
            if (a % (i + 1) == 0 && b % (i + 1) == 0) {
                canDivided[i] = i + 1;
            }
        }
        Arrays.sort(canDivided);
        System.out.println(canDivided[canDivided.length - num]);
    }
}
