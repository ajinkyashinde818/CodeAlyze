import java.util.Scanner;
 
public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int p = scan.nextInt();
        int n = scan.nextInt();
        int[] ar = new int[n];
        for (int i = 0; i < n; i++) {
            int i1 = scan.nextInt();
            ar[i] = i1;
        }
        int min = Integer.MAX_VALUE;
        for (int i = 0; i < ar.length; i++) {
            int x = i == 0 ? n-1:i-1;
            int y = i+1 == ar.length ? 0:i+1;
            min = Math.min(Math.min(p + (ar[x]-ar[i]),p - ar[y] + ar[i]),min);
        }
 
        System.out.println(Math.min(ar[n-1]-ar[0],min));
    }
}
