import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int d = sc.nextInt();
        int g = sc.nextInt();
        int[] p = new int[d];
        int[] c = new int[d];
        for (int i =0; i<d; i++) {
            p[i] = sc.nextInt();
            c[i] = sc.nextInt();
        }
        int min =1001; int count =0; int ans =0;
        for (int i =0; i<Math.pow(2,d); i++) {
            String s = String.format("%" + d + "s", Integer.toBinaryString(i)).replace(' ', '0');
            int n = s.length();
            for (int j=0; j<n; j++) {
                if (s.charAt(j) == '1' ) {
                    count += p[j] * (j + 1) * 100 + c[j];
                    ans += p[j];
                }
            }
            if (count<g) {
                for (int j=n-1; j>=0; j--) {
                    if (s.charAt(j) == '0' ) {
                        int l = p[j];
                        while (count < g && l > 0) {
                            count += (j + 1) * 100;
                            ans++;
                            l--;
                        }
                    }
                }
            }
            if (count >= g) {
                min = Math.min(ans,min);
            }
            count =0;
            ans =0;
        }
        System.out.println(min);
    }
}
