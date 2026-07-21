import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        // Your code here!
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int r = sc.nextInt();
        
        int naibu = 0;
        int hyouji = r;
        
        if (n >= 10) {
            naibu = hyouji;
        } else {
            naibu = hyouji + 100 * (10- n);
        }
        System.out.println(naibu);
    }
}
