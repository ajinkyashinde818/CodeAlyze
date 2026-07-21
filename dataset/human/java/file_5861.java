import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        HashMap<String, Integer> hashmap = new HashMap<>();
        String[] a = sc.next().split("");
        hashmap.put("a", 1);
        hashmap.put("b", 2);
        hashmap.put("c", 3);
        
        if (hashmap.get(a[0]) + hashmap.get(a[1]) + hashmap.get(a[2]) == 6) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
}
