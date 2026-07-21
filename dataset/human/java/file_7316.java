import java.util.Scanner;

public class Main {
    public static void main(String args[]) throws Exception {
        Scanner s = new Scanner(System.in);
        String n = s.next();
        n = n.replaceAll("eraser", "");
        n = n.replaceAll("erase", "");
        n = n.replaceAll("dreamer", "");
        n = n.replaceAll("dream", "");
        
        System.out.println(n.length() == 0 ? "YES": "NO");

    }
}
