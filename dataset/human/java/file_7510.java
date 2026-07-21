import java.util.*;
public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        Set<String> set = new HashSet<String>();
        set.add("dream");
        set.add("dreamer");
        set.add("erase");
        set.add("eraser");
        int idx = s.length();
        String curr = "";
        while (idx >= 5) {
            if (set.contains(s.substring(idx - 5, idx))) {
                idx -= 5;
            } else if (set.contains(s.substring(idx - 6, idx))) {
                idx -= 6;
            } else if (set.contains(s.substring(idx - 7, idx))){ 
                idx -= 7;
            } else {
                break;
            }
        }
        String res =  idx == 0 ? "YES" : "NO";
        System.out.println(res);
    }
}
