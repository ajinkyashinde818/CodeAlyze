import java.util.Scanner;


public class Main{

    public static void main(String []args){
       Scanner scan = new Scanner(System.in);
       int A = scan.nextInt();
       int B = scan.nextInt();
       int K = scan.nextInt();

        int count = 0;
        int ans = 0;

        int N = 0;
        
        for(int i=1; i<=Math.min(A,B); i++){
            if(A%i ==0 && B%i==0){
                N += 1;
            }
        }

        K = N-K+1;

        for(int i=1; count<K; i++){
            if(A%i ==0 && B%i==0){
                ans = i;
                count += 1;
            }
        }
        System.out.println(ans);
   
       scan.close();
    }
}
