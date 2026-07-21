import java.util.*;
 
public class Main {
    
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String S = sc.next();
        String T = sc.next();
        String[] s = S.split("");
        String[] t = T.split("");
        Arrays.sort(s);
        Arrays.sort(t, Collections.reverseOrder());
        StringBuilder sb = new StringBuilder();
        for(int i=0; i<s.length; i++) { 
            sb.append(s[i]);
        }
        S = String.valueOf(sb);
        sb = new StringBuilder();
        for(int i=0; i<t.length; i++) { 
            sb.append(t[i]);
        }
        T = String.valueOf(sb);
        if(S.compareTo(T) < 0) {
            System.out.println("Yes");
        }else {
            System.out.println("No");
        }
    }
}
