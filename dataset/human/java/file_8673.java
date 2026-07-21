import java.util.*;
public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a=sc.nextInt();
        int b=sc.nextInt();
        int tmp1=Euclid(a,b);
        int tmp2=0;
        int k=sc.nextInt();
        for(int i=a;i>0;i--){
            if(tmp1%i==0){
                tmp2++;
                if(tmp2==k){
                    System.out.println(i);
                    return;
                }
            }
        }
    }
        private static int Euclid(int n, int m) {
        int tmp;
        while (true) {
            if (n == 0) {
                return m;
            } else if (m == 0) {
                return n;
            }
            tmp = n;
            n = m;
            m = tmp;
            n = n % m;

        }
        }
}
