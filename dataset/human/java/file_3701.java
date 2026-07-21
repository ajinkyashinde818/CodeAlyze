import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        String x = scan.next();
        String y = scan.next();

        Map<String, Integer> test = new HashMap<>();
        test.put("A", 10);
        test.put("B", 11);
        test.put("C", 12);
        test.put("D", 13);
        test.put("E", 14);
        test.put("F", 15);

        if(test.get(x)>test.get(y)) {
            System.out.println(">");
        } else if (test.get(x)<test.get(y)) {
            System.out.println(("<"));
        } else {
            System.out.println("=");
        }
    }
}
