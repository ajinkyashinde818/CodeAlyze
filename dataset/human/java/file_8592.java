import java.util.*;

public class Main {


    public static void main(String[] args) {

        Scanner sc = new Scanner(System.in);
        int A = sc.nextInt();
        int B = sc.nextInt();
        int K = sc.nextInt();

        int deved =0;

        for(int i=100;i>0;i--){
            if(A % i == 0 && B % i == 0){
                deved++;
            }
            if(deved == K){
                System.out.println(i);
                System.exit(0);
            }

        }


    }


}
