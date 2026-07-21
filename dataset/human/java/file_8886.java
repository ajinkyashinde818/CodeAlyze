import java.util.Scanner;
 
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
 
        int a = sc.nextInt();
        int b = sc.nextInt();
        int k = sc.nextInt();
        int[] n = new int[100];
 
        int min = Math.min(a, b);
        int cnt = 0;
        for (int i = 1; i <= min; i++) {
            if (a % i == 0 && b % i == 0)
                n[cnt++] = i;
            else
                continue;
        }
        
        System.out.println(n[cnt - k]);
    }
}
