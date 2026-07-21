import java.util.*;

public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        int n = sc.nextInt();

        StringBuilder sb1 = new StringBuilder();
        StringBuilder sb2 = new StringBuilder();
        boolean flip = false;

        for(int i=0 ;i<n; i++) {
            int t = sc.nextInt();
            if(t == 1) {
                flip = !flip;
            } else {
                int f = sc.nextInt();
                String c = sc.next();
                if(!flip && f==1 || flip && f==2) {
                    sb1.append(c);
                } else {
                    sb2.append(c);
                }
            }
        }

        if(flip) {
            System.out.print(sb2.reverse().toString());
            System.out.print(new StringBuilder(s).reverse().toString());
            System.out.println(sb1.toString());
        } else {
            System.out.print(sb1.reverse().toString());
            System.out.print(s);
            System.out.println(sb2.toString());
        }
    }
}
