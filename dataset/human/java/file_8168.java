import java.util.*;
public class Main{
  public static void main(String[]args){
      Scanner sc = new Scanner(System.in);

      long m = sc.nextInt();
      long n = sc.nextInt();

      long k = 0;
      boolean stop = false;

      if(m<n) {
        k = m;
      }
      else{
        k = n;
      }
        for(;k>=1&&stop==false;k--){
          if(n%k==0&&m%k==0){
            stop=true;
      }

     }

      long l = n*m/(k+1);
        System.out.println(l);
}
}
