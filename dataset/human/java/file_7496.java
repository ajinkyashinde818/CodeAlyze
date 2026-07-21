import java.util.*;

public class Main {
    static String str;
    static char[] c;
    static boolean ok;
    
    public static void main(String[] args) throws Exception {
        // Your code here! 
        Scanner sc = new Scanner(System.in);
        str = sc.next();
        c = str.toCharArray();
        
        dfs(0);
        
        if (ok) {
            System.out.println("YES");
        } else {
            System.out.println("NO");
        }
    }
    
    public static void dfs(int i) {
        // 終了条件: 最大のルンルン数は10桁なので11桁以上は不要
        if (i == c.length) {
            ok = true;
            return;
        }
        
        // System.out.println(i);
        
        boolean ok5 = false;
        boolean ok7 = false;
        boolean ok6 = false;
        
        if (i+4 < c.length && c[i] == 'd' && c[i+1] == 'r' && c[i+2] == 'e' && c[i+3] == 'a' && c[i+4] == 'm') ok5 = true;
        if (i+4 < c.length && c[i] == 'e' && c[i+1] == 'r' && c[i+2] == 'a' && c[i+3] == 's' && c[i+4] == 'e') ok5 = true;
        if (i+6 < c.length && c[i] == 'd' && c[i+1] == 'r' && c[i+2] == 'e' && c[i+3] == 'a' && c[i+4] == 'm' && c[i+5] == 'e' && c[i+6] == 'r') ok7 = true;
        if (i+5 < c.length && c[i] == 'e' && c[i+1] == 'r' && c[i+2] == 'a' && c[i+3] == 's' && c[i+4] == 'e' && c[i+5] == 'r') ok6 = true;
        
        
        // 次の桁はlast-1, last+0, last+1のパターン
        if (ok5) {
            dfs(i + 5);
        }
        if (ok7) {
            dfs(i + 7);
        }
        if (ok6) {
            dfs(i + 6);
        }
    }
}
