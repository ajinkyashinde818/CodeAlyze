import java.util.Scanner;

public class Main {

    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();

        for(int i=1; i*(i+1)/2 <= n; i++) {
            if( i*(i+1)/2 == n) {
                System.out.println("Yes");
                System.out.println(i+1);
                sub(i);
                return;
            }
        }
        System.out.println("No");
    }

    private static void sub(int m) {
        int[][] a = new int[m][];
        a[0] = new int[m];
        System.out.print(m);
        for(int i =0; i<m ;i++) {
            a[0][i] = i;
            System.out.print(" ");
            System.out.print(i + 1);
        }
        System.out.println();
        int next = m;
        int ai = 1;
        for(int i=0; i<m; i++) {
            System.out.print(m);
            int rem = m - ai;
            for(int j=0; j<ai; j++) {
                System.out.print(" ");
                System.out.print(a[j][ai-j-1] + 1);
            }
            if(rem > 0) {
                a[ai] = new int[rem];
                for (int j = 0; j < rem; j++) {
                    a[ai][j] = next++;
                    System.out.print(" ");
                    System.out.print(a[ai][j] + 1);
                }
                ai++;
            }
            System.out.println();
        }


    }
}
