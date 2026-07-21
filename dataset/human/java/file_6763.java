import java.util.*;

/*
問題文


*/

public class Main {
    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);
        int k = sc.nextInt();
        int n = sc.nextInt();
        int a[] = new int[n];

        for (int i = 0; i < n; i ++) {
            a[i] = sc.nextInt();
        }

        int max = a[0] - a[n - 1] + k;

        for (int i = 0; i < n-1; i ++) {
            if (a[i+1]-a[i] > max) {
                max = a[i+1]-a[i];
            }
        }

        System.out.println(k-max);
    }
}
