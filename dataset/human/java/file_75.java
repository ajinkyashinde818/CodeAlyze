import java.util.Scanner;
 
class Main {
  static Scanner sc = new Scanner(System.in);
    public static void main(String[] args) {
		
       int X = sc.nextInt();
       long min=1192119211;
       int flag = 0;
       long nam = 0;
      
      for(int i=0;i<X;i++){
        long A = sc.nextLong();
        if(A<0){flag++;}
        nam += Math.abs(A);
        min = Math.min(min,Math.abs(A));
      }

	if(flag%2==0){System.out.print(nam);}
      else{System.out.print(nam-min*2);}
      
    }
}
