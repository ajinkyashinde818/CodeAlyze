import java.util.*;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        int A = sc.nextInt();
        int B = sc.nextInt();
        
        if(A>=B){
            for(long i=1; i<=Math.pow(10, 10)/A; i++){
                if(A*i%A==0 && A*i%B==0){
                    System.out.println(A*i);
                    break;
                }
            }
        }
        else if (A<B){
            for(long i=1; i<=Math.pow(10,10)/B; i++){
                if(B*i%A==0 && B*i%B==0){
                    System.out.println(B*i);
                    break;
                }
            }
        }
    }
}
