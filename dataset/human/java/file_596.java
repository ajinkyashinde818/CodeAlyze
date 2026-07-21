import java.util.*;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
      int r = sc.nextInt();
      int nr = 0;
      if(n>=10){
         nr = r;
         System.out.println(nr);
      }else{
         nr = r+100*(10-n);
         System.out.println(nr);
      }
	}
}
