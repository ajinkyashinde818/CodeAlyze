import java.util.ArrayList;
import java.util.Collections;
import java.util.HashSet;
import java.util.Scanner;
public class Main {
    public static int matchsticks[] = {0,2,5,5,4,5,6,3,7,6};
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int untastyAntidote = sc.nextInt();
        int tastyAntidote = sc.nextInt();
        int tastyPoison = sc.nextInt();
        int ans = 0;
        int min = Math.min(untastyAntidote,tastyPoison);
        ans += min;
        tastyPoison -= min;
        min = Math.min(tastyAntidote,tastyPoison);
        ans += 2 * min;
        tastyAntidote -= min;
        tastyPoison -= min;
        if(tastyPoison > 0){
            ans++;
        }
        ans += tastyAntidote;
        System.out.println(ans);
    }
}
