import java.util.*;
import static java.lang.System.*;
public class Main {
public static void main(String[] args){
Scanner sc = new Scanner(in);
int ans=0;
int k = Integer.parseInt(sc.next());
int s = Integer.parseInt(sc.next());
    for (int i = 0; i <= k; i++) {
        for (int j = 0; j <= k; j++) {
            int z=s-i-j;
            if(0<=z&&z<=k)ans++;
        }
    }
    out.println(ans);
}}
