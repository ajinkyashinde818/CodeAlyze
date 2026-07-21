import java.util.*;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String x = sc.next();
        String y = sc.next();

        HashMap<String, Integer> hex = new HashMap<String, Integer>();
        hex.put("A", 10);
        hex.put("B", 11);
        hex.put("C", 12);
        hex.put("D", 13);
        hex.put("E", 14);
        hex.put("F", 15);

        if (hex.get(x) > hex.get(y)) {
            System.out.println(">");
        } else if (hex.get(x) == hex.get(y)) {
            System.out.println("=");
        } else {
            System.out.println("<");
        }
    }
}
