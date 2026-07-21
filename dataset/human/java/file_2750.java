import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        char[] s = sc.nextLine().toCharArray();
        char[] t = sc.nextLine().toCharArray();

        Arrays.sort(s);
        String ss = new String(s);

        Arrays.sort(t);
        String tt = new String(t);
        String td = new StringBuilder(tt).reverse().toString();

        String ans;

        if (ss.compareTo(td) < 0) {
            ans = "Yes";
        } else {
            ans = "No";
        }


        System.out.println(ans);
    }

    public static int solve(int[] A) {
        int ans = 0;
        boolean tf = true;

        for (int a: A) {
            if (a % 2 != 0) {
                tf = false;
            }
        }

        while (tf) {
            for (int i = 0; i < A.length; i++) {
                A[i] = A[i] / 2;
            }
            ans++;

            for (int a: A) {
                if (a % 2 != 0) {
                    tf = false;
                }
            }
        }

        return ans;
    }



}
