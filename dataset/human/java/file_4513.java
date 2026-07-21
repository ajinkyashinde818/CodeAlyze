import java.util.*;

public class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        long a = sc.nextLong();
        long b = sc.nextLong();
        long c = sc.nextLong();

        long ans = b + Math.min(c,a+ b + 1);
        System.out.println(ans);
    } 
}
