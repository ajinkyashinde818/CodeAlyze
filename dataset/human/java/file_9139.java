import java.util.*;

public class Main {

    public static void main(String args[]) {

        Scanner sc = new Scanner(System.in);

        int mod = (int)1e9 + 7;

        int n = sc.nextInt();
        int m = sc.nextInt();

        int block[] = new int[m];

        for (int i=0; i<m; i++){
            block[i] = sc.nextInt();
        }


        int sums[] = new int[n+1];

        boolean stone[] = new boolean[n+1];

        for (int i=0; i<m; i++) {
            stone[block[i]] = true;
        }


        if (m==0) {
            sums[0] = 1;
            sums[1] = 1;

            for (int i = 0; i < n - 1; i++) {
                if (stone[i + 2] == false) {
                    sums[i + 2] = (sums[i + 1] + sums[i]) % mod;
                } else if (stone[i + 2] == true) {
                    sums[i + 2] = 0;
                }
            }

            System.out.println(sums[n] % mod);
            return;

        }
        if (block[0]==0) {System.out.println(0);}
        else if (block[0]==1) {
            sums[0] = 1;
            sums[1] = 0;

            for (int i = 0; i < n - 1; i++) {
                if (stone[i + 2] == false) {
                    sums[i + 2] = (sums[i + 1] + sums[i]) % mod;
                } else if (stone[i + 2] == true) {
                    sums[i + 2] = 0;
                }
            }

            System.out.println(sums[n] % mod);

        }
        else{
            sums[0] = 1;
            sums[1] = 1;

            for (int i = 0; i < n - 1; i++) {
                if (stone[i + 2] == false) {
                    sums[i + 2] = (sums[i + 1] + sums[i]) % mod;
                } else if (stone[i + 2] == true) {
                    sums[i + 2] = 0;
                }
            }

            System.out.println(sums[n] % mod);
        }


    }

}
