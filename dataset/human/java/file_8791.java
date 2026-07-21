import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = Integer.parseInt(sc.next());
        int b = Integer.parseInt(sc.next());
        int k = Integer.parseInt(sc.next());
        List<Integer> list = new ArrayList<>();
        for(int i = min(a, b); i > 0; i--) {
            if(a % i == 0 && b % i == 0) {
                list.add(i);
            }
        }
        System.out.println(list.get(k-1));
    }
    
    public static int min(int a, int b) {
        if(a <= b) {
            return a;
        }else {
            return b;
        }
    }
}
