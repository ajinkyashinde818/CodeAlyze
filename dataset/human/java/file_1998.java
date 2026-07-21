import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        long n = in.nextLong();
        int rootN = root(n);
        int ans = 0;
        for(int i=2; i<rootN; i++) {
            int c = 0;
            while(n%i == 0) {
                n = n / i;
                c++;
            }
            for(int j=1; j<100; j++) {
                if(c>=j) {
                    ans++;
                    c-=j;
                }
                else {
                    break;
                }
            }
        }
        if(n>1) {
            ans++;
        }
        System.out.println(ans);
    }
    private static int root(long n) {
        return (int)Math.ceil(Math.sqrt(n));
    }
}
