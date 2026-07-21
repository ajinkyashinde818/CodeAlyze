import java.io.InputStream;
import java.io.PrintStream;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) throws Exception {
        solve(System.in, System.out);
    }

    static void solve(InputStream is, PrintStream os) {
        // Your code here!
        Scanner scan = new Scanner(is);
        String S = scan.next();
        int Q = scan.nextInt();
        StringPointer headP = null;
        StringPointer tailP = null;
        StringPointer now = new StringPointer(S);
        headP = now;
        tailP = now;

        boolean isReverse = false;
        for(int i = 0; i < Q; i++){
            int T = scan.nextInt();
            if(T == 1) {
                isReverse = !isReverse;
            } else if (T == 2) {
                int F = scan.nextInt();
                String C = scan.next();
                now = new StringPointer(C);
                if(F == 1) {
                    if(isReverse) {
                        tailP.next = now;
                        tailP = now;
                    } else {
                        now.next = headP;
                        headP = now;
                    }
                } else if(F == 2) {
                    if(isReverse) {
                        now.next = headP;
                        headP = now;
                    } else {
                        tailP.next = now;
                        tailP = now;
                    }
                }
            }
        }

        StringBuilder sb = new StringBuilder();

        now = headP;
        while(now != null) {
            sb.append(now.str);
            now = now.next;
        }

        if (isReverse)
            os.println(sb.reverse().toString());
        else
            os.println(sb.toString());

    }

    static class StringPointer {
        StringPointer next = null;
        String str = null;
        StringPointer(String str) {
            this.str = str;
        }
    }


}
