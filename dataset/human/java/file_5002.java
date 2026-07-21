import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        StringBuilder s = new StringBuilder(sc.next());
        //後ろに追加していくSB
        StringBuilder s1 = new StringBuilder();
        //前に追加するSB
        StringBuilder s2 = new StringBuilder();
        int q = sc.nextInt();
        boolean isreversed = false;
        for (int i = 0; i < q; i++) {
            int t = sc.nextInt();
            if (t == 1) {
                isreversed = !isreversed;
            } else {
                int f = sc.nextInt();
                String c = sc.next();
                if (f == 1) {
                    if (isreversed)
                        s1.append(c);
                    else
                        s2.append(c);
                } else {
                    if (isreversed)
                        s2.append(c);
                    else
                        s1.append(c);
                }
            }
        }
        
        s.append(s1);
        s.insert(0, s2.reverse());
        if (isreversed)
            s = s.reverse();
        System.out.println(s.toString());
    }
}
