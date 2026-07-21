import java.util.*;

public class Main {

    static int MOD = 1000000007;
    public static void main(String[] args) {


        Scanner sc = new Scanner(System.in);
        int k=sc.nextInt(),s=sc.nextInt();
        int ans=0;
        for(int i=0;i<k+1;i++)for(int j=0;j<k+1;j++){
            if(i+j<=s&&i+j+k>=s)ans++;
        }
        System.out.println(ans);

    }

}
