import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String s = in.next();
        StringBuilder sbHead = new StringBuilder();
        StringBuilder sbTail = new StringBuilder();
        int q = in.nextInt();
        int asc = 1;
        for(int i=0; i<q; i++) {
            int t = in.nextInt();
            if(t==1) {
                asc *= -1;
                continue;
            }
            int f = in.nextInt();
            String c = in.next();
            if((asc>0&&f==1) || (asc<0&&f==2)) {
                sbHead.insert(0, c);
            }
            else {
                sbTail.append(c);
            }
        }
        if(asc>0) {
            System.out.println(sbHead.toString() + s + sbTail.toString());
        }
        else {
            StringBuilder sb = new StringBuilder(s);
            System.out.println(sbTail.reverse().toString() + sb.reverse().toString() + sbHead.reverse().toString());
        }
    }
}
