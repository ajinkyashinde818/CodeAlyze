import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        String str = sc.next();
        str = str.replaceAll("eraser", "-");
        str = str.replaceAll("erase", "-");
        str = str.replaceAll("dreamer", "-");
        str = str.replaceAll("dream", "-");
        str = str.replaceAll("-", "");
        if (str.length() == 0) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }
}
