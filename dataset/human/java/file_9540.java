import java.util.*;
import java.io.*;
class Main {
    static boolean isPossible(int[][] a) {
        for(int i = 2; i<a.length; i++) {
            if(a[i][0]==a[i][1] && a[i-1][0]==a[i-1][1] && a[i-2][0]==a[i-2][1]) return true;
        }
        return false;
    }
    public static void main (String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int[][] a = new int[n][2];
        for(int i = 0; i<n; i++) {
            a[i][0] = sc.nextInt();
            a[i][1] = sc.nextInt();
        }
        if(isPossible(a)) System.out.println("Yes");
        else System.out.println("No");
    }
}
