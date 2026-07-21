import java.util.Scanner;

public class Main {

    public static void main(String[] args){

        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long[] a = new long[n];
        for(int i=0; i<n; i++) {
            a[i] = sc.nextLong();
        }

        long res = 0;
        int negc = 0;
        long absmin = Integer.MAX_VALUE;

        for(int i=0; i<n; i++) {
            absmin = Math.min(absmin, Math.abs(a[i]));
            res +=  Math.abs(a[i]);
            if (a[i] < 0) {
                negc++;
            }
        }

        if(negc % 2 == 1) {
            res -= absmin * 2;
        }

        System.out.println(res);

    }


}
