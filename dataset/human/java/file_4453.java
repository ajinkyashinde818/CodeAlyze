import java.util.*;

public class Main {// Main
    public static void main(String[] args){

        Scanner var = new Scanner(System.in);

        int A = var.nextInt(); 
        int B = var.nextInt();
        int C = var.nextInt();

        
        if (A+B >= C){
            System.out.println(B+C);
        }else if(A+B < C){
            System.out.println(2*B+A+1);
        }





    }

}
