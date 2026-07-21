import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String n = sc.next();
        boolean containsNine = false;
        for (char num : n.toCharArray()) {
            if (num == '9') containsNine = true;
        }
        if (containsNine) {
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }
}
