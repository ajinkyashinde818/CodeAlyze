import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        String[] a = sc.next().split("");
        String[] b = sc.next().split("");
        Arrays.sort(a);
        Arrays.sort(b, Comparator.reverseOrder());
        String one = "";
        String two = "";
        for (String tmp : a) {
            one += tmp;
        }
        for (String tmp : b) {
            two += tmp;
        }
        if (one.compareTo(two) < 0) {
            System.out.println("Yes");    
        } else {
            System.out.println("No");
        }
        
    }
}
