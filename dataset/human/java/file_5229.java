import java.util.*;
 
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        StringBuilder sb = new StringBuilder();
        sb.append(sc.next());
        StringBuilder sbl = new StringBuilder();
        StringBuilder sbr = new StringBuilder();
        int normal = 1;
        int q = Integer.parseInt(sc.next());
        for(int i=0; i<q; i++) {
            int t = Integer.parseInt(sc.next());
            if(t == 1) {
                if(normal==1) normal = -1;
                else normal = 1;
            }else {
                int f = Integer.parseInt(sc.next());
                String c = sc.next();
                if(f == 1) {
                    if(normal==1) sbl.append(c);
                    else sbr.append(c);
                }
                else {
                    if(normal==1) sbr.append(c);
                    else sbl.append(c);
                }
            }
        }
        if(normal==1) {
            System.out.println(sbl.reverse()+String.valueOf(sb)+sbr);
        }else {
            System.out.println(sbr.reverse()+String.valueOf(sb.reverse())+sbl);
        }
    }
}
