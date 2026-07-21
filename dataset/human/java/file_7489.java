import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String s = sc.nextLine();
        s = s.replace("eraser", "");
        s = s.replace("erase", "");
        s = s.replace("dreamer", "");
        s = s.replace("dream", "");
        System.out.println(s.equals("") ? "YES" : "NO");
    }
}
