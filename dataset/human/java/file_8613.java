import java.util.*;

public class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);

        int A = sc.nextInt();
        int B = sc.nextInt();
        int K = sc.nextInt();
        int x = 0;

        if(A<=B){
            for(int i=A; i>0; i--){
                if(A%i==0 && B%i==0){
                    x += 1;
                    if(x==K){
                        System.out.println(i);
                    }
                }
            }
        }
        else if(A>B){
            for( int i=B; i>0; i--){
                if(A%i==0 && B%i==0){
                    x += 1;
                    if(x==K){
                        System.out.println(i);
                    }
                }
            }
        }
    }
}
