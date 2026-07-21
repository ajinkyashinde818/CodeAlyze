import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int A = sc.nextInt();
        int B = sc.nextInt();
        int k = sc.nextInt();
        int min = Math.min(A,B);
        int count = 0;
        int val = 0;

        for(int i = min; i >= 1; i--) {
            if(A%i==0 && B%i==0){
                count++;
                val = i;
                if(count == k) break;
            }
        }
        System.out.println(val);
    }
}
