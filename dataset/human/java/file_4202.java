import java.util.*;
 
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int[] order = new int[N+1];
        int[] satisfaction = new int[N+1];
        int[] combo = new int[N];
        for (int i = 1; i <= N; i++) {
        	order[i] = sc.nextInt();
        }
        for (int i = 1; i <= N; i++) {
        	satisfaction[i] = sc.nextInt();
        }
        for (int i = 1; i < N; i++) {
        	combo[i] = sc.nextInt();
        }
        int total = 0;
        int tmp = 0;
        for (int i = 1; i <= N; i++) {
        	total += satisfaction[order[i]];
        	if (tmp == order[i] - 1) {
        		total += combo[tmp];
        	}
        	tmp = order[i];
        }
        System.out.println(total);
    }
}
