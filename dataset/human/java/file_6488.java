import java.util.*;

class Main{
    public static void main(String[] args) {
        Scanner stdIn = new Scanner(System.in);
        int k = stdIn.nextInt();
        int s = stdIn.nextInt();
        int ans = 0;
        for(int i = 0; i <= k; i++){
            for(int j = 0; j <= k; j++){
                if(s - (i+j)  <= k && 0 <= s - (i + j)) ans++;
            }
        }
        System.out.println(ans);
    }
}
