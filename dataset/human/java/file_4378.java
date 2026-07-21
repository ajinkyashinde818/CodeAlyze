import java.util.Scanner;

public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) {
        
        Scanner s = new Scanner(System.in);
        int n = s.nextInt();
        
        int[] as = new int[n];
        int[] bs = new int[n];
        int[] cs = new int[n - 1];
        
        for (int i = 0; i < n; i ++) {
            as[i] = s.nextInt();
        }
        
        for (int i = 0; i < n; i ++) {
            bs[i] = s.nextInt();
        }
        
        for (int i = 0; i < n - 1; i ++) {
            cs[i] = s.nextInt();
        }
        
        
        int points = 0;
        
        for (int i = 0; i < n; i ++) {
            points += bs[as[i] - 1];
            if (i > 0 && as[i] == as[i - 1] + 1) {
                points += cs[as[i - 1] - 1];
            }
        }
        
        System.out.println(points);
    }
    
}
