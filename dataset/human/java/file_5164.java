import java.util.*;
import java.math.*;
class Main {
    //
    static final int MOD = 1_000_000_007; // 10^9+7
    //static final int MAX = 2_147_483_646; // intの最大値
    static final int INF = 1_000_000_000; // 10^9
    static final int MAX = 10_000_000;
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        String s = sc.next();
        StringBuffer mae = new StringBuffer("");
        StringBuffer usiro = new StringBuffer("");
        int n = sc.nextInt();
        boolean rev = false;
        for(int i = 0;i < n;i++){
            int t = sc.nextInt();
            if(t==1){
                if(rev){
                    rev = false;
                }else{
                    rev = true;
                }
            }else{
                int f = sc.nextInt();
                String c = sc.next();
                if(rev){
                    if(f==1){
                        usiro.append(c);
                    }else{
                        mae.insert(0, c);
                    }
                }else{
                    if(f==1){
                        mae.insert(0, c);
                    }else{
                        usiro.append(c);
                    }
                }
            }
        }
        if(rev){
            StringBuffer str = new StringBuffer(s);
            System.out.println(usiro.reverse().toString()+str.reverse().toString()+mae.reverse().toString());
        }else{
            System.out.println(mae.toString()+s+usiro.toString());
        }
    }
}
