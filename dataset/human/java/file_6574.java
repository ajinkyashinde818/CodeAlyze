import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);
        int k = scan.nextInt();
        int s = scan.nextInt();

        int count = 0;

        for(int x = 0; x <=  s; x++) {
            if(x <= k) {
                for(int y = 0; y <= s - x; y++) {
                    if (y <= k && s - x - y <= k){
                        count += 1;
                    }
                }
            }
        }
        System.out.println(String.valueOf(count));

    }
}
