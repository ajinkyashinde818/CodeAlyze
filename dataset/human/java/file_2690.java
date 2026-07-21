import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String args[]){
        Scanner scanner = new Scanner(System.in);
        char ca[] = scanner.next().toCharArray();
        char cb[] = scanner.next().toCharArray();
        Arrays.sort(ca);
        Arrays.sort(cb);
        for (int i = 1;i <= cb.length;++i){
            if(i > ca.length){
                System.out.println("Yes");
                return;
            }
            if(ca[i - 1] > cb[cb.length - i]){
                System.out.println("No");
                return;
            }
            else if(ca[i - 1] < cb[cb.length - i]){
                System.out.println("Yes");
                return;
            }
        }
        System.out.println("No");
    }
}
