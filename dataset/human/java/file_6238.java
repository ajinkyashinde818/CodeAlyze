import java.lang.reflect.Array;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int k = sc.nextInt(), s = sc.nextInt(), ret = 0;
        for(int i=0;i<=k;i++)for(int j=0;j<=k;j++){
            if(0<=s-i-j && s-i-j<=k)ret+=1;
        }
        System.out.println(ret);
    }
}
