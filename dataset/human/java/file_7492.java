import java.util.*;

public class Main {
    static int modP = 1000000007;

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        String s = in.next();

        int idx = s.length();
        boolean cond = false;
        while(idx >= 0) {
            if(cond) break;
            if(idx < 5) {
                print("NO");
                return;
            }

            String last5 = s.substring(idx-5, idx);
            if(last5.equals("dream") || last5.equals("erase")) {
                idx -= 5;
                if(idx == 0) cond = true;
                continue;
            }

            String last6 = s.substring(idx-6, idx);
            if(last6.equals("eraser")) {
                idx -= 6;
                if(idx == 0) cond = true;
                continue;
            }

            String last7 = s.substring(idx-7, idx);
            if(last7.equals("dreamer")) {
                idx -= 7;
                if(idx == 0) cond = true;
                continue;
            }

            break;
        }

        if(cond) {
            print("YES");
        }else{
            print("NO");
        }
    }

    static void print(String s) {
        System.out.println(s);
    }

    static void print(int i) {
        System.out.println(i);
    }
}
