import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        long A = Integer.parseInt(sc.next());
        long B = Integer.parseInt(sc.next());
        long i = 1;
        if(A<B){
            long temp = A;
            A = B;
            B = temp;
        }
        while(true){
            if((A*i)%B == 0){
                System.out.println(A*i);
                return;
            }
            i++;
        }
    }
}
