import java.util.*;
 
public class Main {
    public static void main(String[] args) throws Exception {
        
        Scanner sc = new Scanner(System.in);
        char[] s = sc.next().toCharArray();
        char[] t = sc.next().toCharArray();
        Arrays.sort(s);
        String s_1 = new String(s);
        Arrays.sort(t);
        StringBuilder sb = new StringBuilder(new String(t));
        sb.reverse();
        String ans = s_1.compareTo(sb.toString()) < 0 ? "Yes" : "No";
        System.out.println(ans);
    }
}
