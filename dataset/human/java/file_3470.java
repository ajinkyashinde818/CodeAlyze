import java.util.*;

public class Main{
    void solve(){
        Scanner scan = new Scanner(System.in);
        int a = (int)scan.next().charAt(0);
        int b = (int)scan.next().charAt(0);
        if(a < b) System.out.println("<");
        else if(a == b) System.out.println("=");
        else System.out.println(">");
    }
    
    public static void main(String[] args){
        new Main().solve();
    }
}
