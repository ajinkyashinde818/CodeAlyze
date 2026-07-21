import java.util.*;

public class Main{
    void solve(){
        Scanner scan = new Scanner(System.in);
        String s = scan.next();
        char[] c = new char[3];
        for(int i = 0; i < 3; i++) c[i] = s.charAt(i);
        Arrays.sort(c);
        System.out.println(c[0] == 'a' && c[1] == 'b' && c[2] == 'c' ? "Yes" : "No");
        scan.close();
    }

    public static void main(String[] args){
        new Main().solve();
    }
}
