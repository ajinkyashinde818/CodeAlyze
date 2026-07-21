import java.util.*;


public class Main{
    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int k = sc.nextInt();
        int s = sc.nextInt();
        sc.close();
        int x = 0;
        int y = 0;
        int z = 0;
        int count = 0;

        for(x = 0; x <= k; x++) {
            for(y = 0; y <= k; y++){
                z = s - (x+y);
                if (z <= k && z >= 0) {
                    count++;
                }
            }
        }

        System.out.println(count);
    }
}
