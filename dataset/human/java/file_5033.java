import java.util.*;

public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        StringBuffer s = new StringBuffer(sc.next());
        int q = sc.nextInt();
        int pn = 0;
        StringBuffer plus = new StringBuffer();
        StringBuffer minus = new StringBuffer();
        for (int i=0;i<q;i++){
            if (sc.nextInt()==1){
                pn++;
            }else {
                if ((sc.nextInt()-1+pn)%2==0){
                    plus.append(sc.next());
                }else {
                    minus.append(sc.next());
                }
            }
        }
        if (pn%2==1){
            plus.reverse();
            s.append(minus);
            s.insert(0,plus);
        }else {
            s.reverse();
            minus.reverse();
            s.append(plus);
            s.insert(0,minus);
        }
        s.reverse();
        System.out.println(s);
    }
}
