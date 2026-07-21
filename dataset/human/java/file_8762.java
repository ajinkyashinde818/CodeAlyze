import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int k = sc.nextInt();

        ArrayList<Integer> ans = new ArrayList<>();
        for(int i=1; i<=a; i++) {
            if(a % i == 0) {
                for(int j=1; j<=b; j++) {
                    if(b % j == 0 && i == j) {
                        ans.add(i);
                    }
                }
            }
        }

        Collections.sort(ans, Collections.reverseOrder());
        System.out.println(ans.get(k-1));
    }
}
