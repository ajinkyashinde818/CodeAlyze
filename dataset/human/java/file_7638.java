import java.util.*;

public class Main {
    public static void main(String[] args) throws Exception {
        // Your code here!
        Scanner sc = new Scanner(System.in);
        Random random = new Random();
        int n = sc.nextInt();
        long k = sc.nextLong();
        
        int[] to = new int[n];
        for (int i = 0; i < n; i++) {
            to[i] = sc.nextInt()-1;
        }
        
        // ans:
        // array = {2,4,<16,256,471,620>}について、
        // 「i=0からスタートし、">"まで来たら"<"に戻る」ルールで、
        // 操作「i = to[i]」をk回したときのi
        
        // array:
        // ex. to = {6,5,2,5,3,2} (1-indexed)
        // array = {1,6,<2,5,3>}
        
        // how: ρの形で考えて3パターンでそれぞれ集計する。
        
        Set<Integer> set = new HashSet<Integer>();
        List<Integer> list = new ArrayList<Integer>();
        int now = 0;
        set.add(now);
        list.add(now);
        int last = 0;
        for (long i = 0; i < k; i++) {
            now = to[now];
            if (set.contains(now)) {
                last = now;
                break;
            } else {
                set.add(now);
                list.add(now);
            }
        }
        // System.out.println(list.toString());
        
        int loop_idx = 0;
        for (int i = 0; i < list.size(); i++) {
            if (list.get(i) == last) {
                loop_idx = i;
            }
        }
        
        int ans = 0;
        
        // [start, loop始点)
        for (int i = 0; i < loop_idx; i++) {
            ans = to[ans];
        }
        k -= loop_idx;
        
        // [loop始点, loop終点] * 何周できるか
        long len = list.size() - loop_idx;
        k %= len;
        
        // [loop始点, 残りの移動回数]
        for (int i = loop_idx; i < loop_idx + k; i++) {
            ans = to[ans];
        }
        
        System.out.println(ans+1);
    }
}
