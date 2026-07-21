import java.util.Scanner;

public class Main {
    public static void main(String args[]){
        Scanner sc=new Scanner(System.in);
        long n=sc.nextLong();
        long copyn = n;
        long ans = 0;
        for(int i=2;i<=Math.sqrt(n);i++) {
            int count=1;
            while(n % (Math.pow(i,count)) == 0) {
                n = (long) ( n / Math.pow(i,count));
                count++;
                ans++;
            }

            while(n % i == 0) {
                n = n / i;
            }
        }

        if(copyn == 1) {
            System.out.println(0);
        } else if(n>1) {
            System.out.println( 1 + ans);
        } else {
            System.out.println(ans);
        }

    }
}
