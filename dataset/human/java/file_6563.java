import java.util.*;

class Main{
    void solve(){
        Scanner scan = new Scanner(System.in);
        int k = scan.nextInt();
        int s = scan.nextInt();
        int out = 0;
        for(int i = 0; i <= k; i++){
            for(int j = 0; j <= k; j++){
                int z = s - i - j;
                if(0 <= z && z <= k) out++;
            }
        }
        System.out.println(out);
        scan.close();
    }
    
    public static void main(String[] args){
        new Main().solve();
    }
}
