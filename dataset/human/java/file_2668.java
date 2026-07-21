import java.util.Scanner;
import java.util.Arrays;
import java.util.Collections;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);

        char[] s = sc.nextLine().toCharArray();
        char[] t = sc.nextLine().toCharArray();

        Arrays.sort(s);
        Arrays.sort(t);

        char[] newT = new char[t.length];
        for(int i=0; i<t.length; i++) {
            newT[i] = t[t.length-1-i];
        }

        String ss = new String(s);
        String tt = new String(newT);

        if(ss.compareTo(tt) < 0) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
        sc.close();
    }
}
