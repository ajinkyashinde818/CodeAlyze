import java.io.CharArrayReader;
import java.lang.reflect.Array;
import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();
        boolean flg = true;
        String nn[] = new String[n];
        String mm[] = new String[m];
        for(int i=0;i<n;i++)nn[i]=sc.next();
        for(int i=0;i<m;i++)mm[i]=sc.next();
        for(int x=0;x<=n-m;x++)for(int y=0;y<=n-m;y++){
            flg = true;
            for (int k = 0; k < m; k++){
                if(!mm[k].equals(nn[y+k].substring(x, x+m))){
                    flg = false;
                    break;
                }
            }
            if(flg){
                System.out.println("Yes");
                System.exit(0);
            }

        }
        System.out.println("No");
    }
}
