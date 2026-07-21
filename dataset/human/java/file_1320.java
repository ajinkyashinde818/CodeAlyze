import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        // Your code here!
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        
        char[][] boarda = new char[n][n];
        for (int i = 0; i < n; i++) {
            String str = sc.next();
            for (int j = 0; j < n; j++) {
                boarda[i][j] = str.charAt(j);
            }
        }
        char[][] boardb = new char[n][n];
        for (int i = 0; i < m; i++) {
            String str = sc.next();
            for (int j = 0; j < m; j++) {
                boardb[i][j] = str.charAt(j);
            }
        }
        
        boolean ok = true;
        for (int offseti = 0; offseti <= n - m; offseti++) {
            for (int offsetj = 0; offsetj <= n - m; offsetj++) {
                ok = true;
                for (int i = 0; i < m; i++) {
                    for (int j = 0; j < m; j++) {
                        if (boardb[i][j] != boarda[i+offseti][j+offsetj]) {
                            ok = false;
                        }
                    }
                }
                
                if (ok) {
                    System.out.println("Yes");
                    return;
                }
            }
        }
        System.out.println("No");
    }
}
