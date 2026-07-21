import java.util.Scanner;
import java.lang.Math;
 
public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        long a = sc.nextLong();
		int div = 2;
		int count = 0;
		
		while(Math.sqrt(a) > div ){
			for(int tempdiv = div;a%tempdiv == 0;tempdiv = tempdiv * div){
				a/= tempdiv;
				count++;
			}
            while(a%div==0){
              a/=div;
            }//除爆你
			div++;
			}
      if(a !=1){count++;}
      System.out.print(count);
    }
}
