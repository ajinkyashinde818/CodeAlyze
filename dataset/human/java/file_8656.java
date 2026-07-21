import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int a = sc.nextInt();
        int b = sc.nextInt();
        int k = sc.nextInt();

        int n = 100;
        int count = 0;

        for(int i=0; i<1000; i++){
            if(a%n == 0 && b % n == 0){
                count++;
                if(count == k) break;
            }
            n--;
        }

        System.out.println(n);
        
    }
}
