import java.util.Scanner;

public class Main {

    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        String n = sc.nextLine();
        String s = "0" + n;
        
        char[] ch = s.toCharArray();
        int[] a = new int[ch.length];
        for (int i = 0; i < ch.length; i++) {
            a[i] = ch[i] - '0';
        }

        int ans = 0;
        for (int i = a.length - 1; i > 0; i--) {
            if (a[i] == 5 && a[i - 1] >= 5) {
                a[i - 1]++;
                a[i] -= 10;
            } else if (a[i] > 5) {
                a[i - 1]++;
                a[i] -= 10;
            }
            ans += Math.abs(a[i]);
        }
        ans += Math.abs(a[0]);

        System.out.println( ans );
    }
    
}
