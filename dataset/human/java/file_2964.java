import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        HashSet<Integer> set = new HashSet<>();
        ArrayList<Integer> nIslandPorts = new ArrayList<>();
        for(int i = 0; i < m; i++) {
            int a = sc.nextInt();
            int b = sc.nextInt();
            if(a == 1) set.add(b);
            if(b == n) nIslandPorts.add(a);
        }
        for(Integer num: nIslandPorts) {
            if(set.contains(num)) {
                System.out.println("POSSIBLE");
                return;
            }
        }
        System.out.println("IMPOSSIBLE");
    }

}
