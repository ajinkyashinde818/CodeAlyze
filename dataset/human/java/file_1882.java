import java.math.BigDecimal;
import java.math.MathContext;
import java.util.*;

public class Main {

    static int D;
    static int G;
    static int p[];
    static int c[];

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        D = scanner.nextInt();
        G = scanner.nextInt();
        p = new int[D];
        c = new int[D];
        for (int n = 0;n < D;++n){
            p[n] = scanner.nextInt();
            c[n] = scanner.nextInt();
        }
        System.out.println(search(0,p));
    }

    public static int search(int s,int p[]){
        int min = Integer.MAX_VALUE;
        for (int i = 0;i < D;++i) {
            if(p[i] == 0)continue;
            int t = (G - s) / ((i + 1) * 100);
            if((G - s) % (i * 100 + 100) != 0)++t;
            if (t <= p[i]){
                if(t < min)min = t;
            }
            else {
                int ns = s + p[i] * (i * 100 + 100) + c[i];
                if(ns >= G){
                    if(p[i] < min)min = p[i];
                }
                else {
                    int[] cp = p.clone();
                    cp[i] = 0;
                    int k = search(ns, cp);
                    if (k + p[i] < min)min = k + p[i];
                }
            }
        }
        return min;
    }
}
