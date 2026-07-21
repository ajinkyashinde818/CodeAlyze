import java.util.*;
 
class Main{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
 
        int A = sc.nextInt();
        int B = sc.nextInt();
        int C = sc.nextInt();
 
        if( A + B >= C){
            System.out.println(B + C);
        }else if(Math.max(A, B) < C){
            System.out.println((2*B + A) + 1);
        }
 
    }
}
