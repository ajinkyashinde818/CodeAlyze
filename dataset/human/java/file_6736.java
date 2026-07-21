/* package whatever; // don't place package name! */

import java.util.*;

class Main {
    public static void main (String[] args) {
        Scanner sc = new Scanner(System.in);

        int K = sc.nextInt();
        int N = sc.nextInt();
        sc.nextLine();

        int[] len = new int[N];

        int sum = 0;
        int max = 0;

        for (int i = 0; i < N; i++) {
            len[i] = sc.nextInt();
        }

        for (int i = 1; i < N; i++) {
            int sa = Math.abs(len[i]  - len[i-1]);
            sum += sa;
            
            if (sa > max) {
                max = sa;
            }
        }
        
        if (max > len[0] + K - len[N-1]) {
            sum = sum - max + len[0] + K - len[N-1];
        } 

        System.out.println(sum);
        sc.close();
    }
}
