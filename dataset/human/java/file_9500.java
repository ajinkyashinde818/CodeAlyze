import java.util.*;
import static java.lang.System.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(in);
        int n = sc.nextInt();
        int ren = 0;
        for(int i=0; i<n; i++){
            int a = sc.nextInt();
            int b = sc.nextInt();

            if(a == b) ren++;
            else ren = 0;

            if(ren == 3){
                out.println("Yes");
                break;
            }
        }
        if(ren != 3) out.println("No");
    }
}
