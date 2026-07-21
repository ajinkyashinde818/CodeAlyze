import java.util.*;
public class Main{
        public static void main(String[] args){
                Scanner sc = new Scanner(System.in);
                int n = sc.nextInt();
                int[] a = new int[n];
                long yono = 0;
                long pct = 0;
                for(int i = 0 ; i < n; i++){
                        a[i] = sc.nextInt();
                        yono += a[i];
                }
                yono -= a[n - 1];
                pct += a[n - 1];
                long ebishu = Math.abs(yono - pct);
                for(int i = n - 2 ; i > 0 ; i--){
                        yono -= a[i];
                        pct += a[i];
                        ebishu = Math.min(ebishu , Math.abs(yono - pct));
                }
                System.out.println(ebishu);
        }
}
//TLEかWAになりそうな予感、祈ります
