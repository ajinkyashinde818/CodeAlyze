import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        StringBuilder res = new StringBuilder();
        int t = 1000000000;
        int n = sc.nextInt(), k = sc.nextInt(), s = sc.nextInt();
        int[] A = new int[n];
        for(int i = 0; i < k; i++) A[i] = s;
        if(s == t) t = 1;
        for(int i = k; i < n; i++) A[i] = t;
        for(int i = 0; i < n-1; i++) res.append(A[i] + " ");
        res.append(A[n-1]);
        System.out.println(res);
    }
}
