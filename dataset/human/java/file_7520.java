import java.util.*;

public class Main{
    Scanner in = new Scanner(System.in);

    void solve(){
        String s = in.nextLine();
        int a = s.replace("dreamer", "").replace("dream", "").replace("eraser", "").replace("erase", "").length();
        int b = s.replace("eraser", "").replace("erase", "").replace("dreamer", "").replace("dream", "").length();
        if(a == 0 || b == 0){
            System.out.println("YES");
        }else{
            System.out.println("NO");
        }
    }

    public static void main(String[] args){
        new Main().solve();
    }
}
