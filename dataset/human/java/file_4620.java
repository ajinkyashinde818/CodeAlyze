import java.util.Scanner;

public class Main {
	
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        
        long A = sc.nextLong();
        long B = sc.nextLong();
        long C = sc.nextLong();
        
        long ans = B;
        ans += C - Math.max(C - (A+B+1), 0);
        
        System.out.println(ans);
    }

}
