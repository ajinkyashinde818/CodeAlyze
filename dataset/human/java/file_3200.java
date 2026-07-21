import java.util.*;

public class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        System.out.println(has9(s));
    }
    
    public static String has9(String s) {
        for(int i = 0; i < s.length(); i++) {
            if(s.charAt(i) == '9') {
                return "Yes";
            }
        }
        return "No";
    }
}
