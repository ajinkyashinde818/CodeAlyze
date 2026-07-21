import java.util.*;

public class Main {
    public static void main(String[] args) {
        try(Scanner sc = new Scanner(System.in);) {
            String src = sc.nextLine();
            String res = src.replaceAll("eraser", "").replaceAll("erase", "").replaceAll("dreamer", "").replaceAll("dream", "");
            System.out.println(res.length() == 0 ? "YES" : "NO");
        }
    }
}
