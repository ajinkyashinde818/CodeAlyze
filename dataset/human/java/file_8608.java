import java.util.*;

public class Main {

    public static void main(String[] args) {
	    // write your code here
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int k = sc.nextInt();

        ArrayList<Integer> list = new ArrayList<>();
        for (int i = 1; i <= Math.max(a, b); i++) {
            if (a % i == 0 && b % i == 0) {
                list.add(i);
            }
        }
        // 出力
        System.out.println(list.get(list.size() - k));
    }
}
