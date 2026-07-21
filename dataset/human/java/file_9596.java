import java.util.*;

public class Main{
    void solve(){
        Scanner scan = new Scanner(System.in);
        int n = scan.nextInt();
        boolean[] isZoro = new boolean[n];
        for(int i = 0; i < n; i++){
            if(scan.nextInt() == scan.nextInt()) isZoro[i] = true;
        }
        for(int i = 0; i < n - 2; i++){
            if(isZoro[i] && isZoro[i + 1] && isZoro[i + 2]){
                System.out.println("Yes");
                return;
            }
        }
        System.out.println("No");
    }

    public static void main(String[] args){
        new Main().solve();
    }
}
