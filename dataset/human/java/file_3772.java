import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        HashMap<String, Integer> hashmap = new HashMap<>();
        hashmap.put("A", 10);
        hashmap.put("B", 11);
        hashmap.put("C", 12);
        hashmap.put("D", 13);
        hashmap.put("E", 14);
        hashmap.put("F", 15);
        
        String x = sc.next();
        String y = sc.next();
        
        if (hashmap.get(x) > hashmap.get(y)) {
            System.out.println(">");
        } else if (hashmap.get(x) < hashmap.get(y)) {
            System.out.println("<");
        } else {
            System.out.println("=");
        }
    }
}
