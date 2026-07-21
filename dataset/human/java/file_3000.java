import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        Scanner sc = new Scanner(System.in);
        int N = Integer.parseInt(sc.next());
        int M = Integer.parseInt(sc.next());
        int a, b;
        Map<Integer, List<Integer>> map = new HashMap<>();
        for(int i=0; i<M; i++) {
            a = Integer.parseInt(sc.next());
            b = Integer.parseInt(sc.next());
            if(map.containsKey(a)) map.get(a).add(b);
            else {
                map.put(a, new ArrayList<Integer>());
                map.get(a).add(b);
            }
            if(map.containsKey(b)) map.get(b).add(a);
            else {
                map.put(b, new ArrayList<Integer>());
                map.get(b).add(a);
            }
        }
        
        String ans = "IMPOSSIBLE";
        for(int x : map.get(1)) {
            for(int y : map.get(x)) {
                if(y == N) {
                    ans = "POSSIBLE";
                    break;
                }
            }
        }
        System.out.println(ans);
    }
}
