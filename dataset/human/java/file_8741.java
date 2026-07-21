import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
      
      Scanner sc = new Scanner(System.in);
      
      int a = sc.nextInt();
      int b = sc.nextInt();
      int k = sc.nextInt();
      
      int c;
      
      if(b > a){
        c = a;
       	a = b;
       	b = c;
      }
      
      int count = 0;
      
      for(int i = 1; i <= b; i++){
        if(a % i == 0 && b % i == 0)
        count++;
      }
      
      
      
      int[]d = new int[count];
      int i;
      
      for(i = 0; i < count; i++){
        if(i == 0){
          d[i] = 1;
        } else {
          for(int l = d[i-1]+1; l <= b; l++){
            if(a % l == 0 && b % l == 0){
              d[i] = l;
              break;
        	} 
          }
        }
      }
      
     
     System.out.println(d[count - k]);
      
    }
}
