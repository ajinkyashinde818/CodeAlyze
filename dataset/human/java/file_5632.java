import java.util.*;
public class Main{
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        int N = scan.nextInt();
        int K = scan.nextInt();
        int S = scan.nextInt();
        if(N==K){
            for(int i=0;i<N;i++){
                System.out.print(S);
                System.out.print(" ");
            }
        }else if(S==1000000000){
            for(int i=0;i<K;i++){
                System.out.print(1000000000);
                System.out.print(" ");
            }
            for(int i=0;i<N-K;i++){
                System.out.print(999999999);
                System.out.print(" ");
            }
        }else{
            for(int i=0;i<K;i++){
                System.out.print(S);
                System.out.print(" ");
            }
            for(int i=0;i<N-K;i++){
                System.out.print(S+1);
                System.out.print(" ");
            }
        }
    }
}
