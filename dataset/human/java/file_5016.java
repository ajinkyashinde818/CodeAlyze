import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        int q = sc.nextInt();
        boolean rev = false;
        StringBuilder f = new StringBuilder();
        StringBuilder b = new StringBuilder();
        for (int i = 0; i < q; i++) {
            int t = sc.nextInt();
            if(t == 1){
                rev = !rev;
            }else{
                int a = sc.nextInt();
                String c = sc.next();
                boolean front = (rev&&a==2) || (!rev&&a==1);
                if(front){
                    f.append(c);
                }else{
                    b.append(c);
                }
            }
        }
        StringBuilder ans = f.reverse().append(s).append(b);
        System.out.println(rev ? ans.reverse().toString() : ans.toString());
        sc.close();

    }

}
