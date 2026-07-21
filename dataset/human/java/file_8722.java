import java.util.Scanner;

public class Main {

    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int A = sc.nextInt();
        int B = sc.nextInt();
        int K = sc.nextInt();

        int count =0;
        int div = 100;
        while ( count<K ) {
            if(A%div==0 && B%div==0  ){
                count++;
                if(count==K) break;
            }
            div--;
        }
        System.out.println(div);


    }
}
