import java.util.*;

public class Main{
    
    static final long MOD = (int)1e9+7;
    
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        
        int n = Integer.parseInt(sc.next());
        char[] s = sc.next().toCharArray();
        
        HashMap<Character, Integer> h = new HashMap<>();
        for(char c : s){
            int tmp = h.getOrDefault(c, 0);
            h.put(c, tmp+1);
        }
        
        long ans = 1;
        for(Integer v : h.values()){
            ans *= v+1;
            ans %= MOD;
        }
        
        System.out.println(ans-1);
    }
}
