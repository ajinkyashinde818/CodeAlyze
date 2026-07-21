import java.io.*;
import java.util.*;


public class Main {
    public static void main (String[]args)throws IOException {
        Scanner scanner = new Scanner(System.in);
        int k = scanner.nextInt();
        int n = scanner.nextInt();
        int[] a = new int[n];
        for (int i = 0; i < n; i++) {
            a[i] = scanner.nextInt();
        }
        int minDistance=k-(a[n-1]-a[0]);
        for (int i = 1; i < n; i++)
            minDistance = Math.max(minDistance, a[i] - a[i-1]);
        System.out.println(k-minDistance);
    }
}
