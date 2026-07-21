import java.util.*;
 
class Main {
    public static void main(String[] args) {
      
        Scanner sc = new Scanner(System.in);
        int A = sc.nextInt();
        int B = sc.nextInt();
      	int C = sc.nextInt();
      
      if(A+B+1>=C){System.out.print(B+C);}
      else{System.out.print(B*2+A+1);}
 
    }
}
