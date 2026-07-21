import java.util.*;

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        char[] c = sc.next().toCharArray();
        int n = c.length;


        int a = c[0] - '0';
        int b = 11 - c[0] + '0';
        for(int i=1; i<n; i++) {
            int na = Integer.MAX_VALUE;
            int nb = Integer.MAX_VALUE;
            int num = c[i] - '0';
            if(num == 0) {
                na = Math.min(a, b);
            } else {
                na = Math.min(a, b) + num;
                nb = a + 11 - num;
                if(b != Integer.MAX_VALUE) {
                    nb = Math.min(nb, b + 9 - num);
                }
            }
            a = na;
            b = nb;
        }

        System.out.println(Math.min(a, b));
    }

}
