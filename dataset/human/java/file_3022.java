import java.util.*;
import java.math.*;

public class Main {
    public static void main(String[] args) throws Exception {
        // Your code here!
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.next());
        int m = Integer.parseInt(sc.next());
        HashMap<Integer,Boolean> map = new HashMap<Integer,Boolean>();
        boolean flg = false;
        for(int i=0;i<m;i++){
            int a = Integer.parseInt(sc.next());
            int b = Integer.parseInt(sc.next());
            if(a==1){
                if(map.containsKey(b)){
                    flg = true;
                    break;
                }
                map.put(b, true);
            }
            if(b==n){
                if(map.containsKey(a)){
                    flg = true;
                    break;
                }
                map.put(a, true);
            }
        }
        System.out.println(flg?"POSSIBLE":"IMPOSSIBLE");
    }
}
