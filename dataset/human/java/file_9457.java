import java.util.*;
public class Main {
	public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt(), count = 0;
        for (int i = 0; i < n; i++) {
            int a = sc.nextInt(), b = sc.nextInt();
            if (a != b) {
                count = 0;
                continue;
            }
            count++;
            if (count == 3) {
                System.out.println("Yes");
                return;
            }
        }
        System.out.println("No");
	}
}
