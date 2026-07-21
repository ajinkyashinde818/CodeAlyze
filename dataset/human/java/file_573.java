import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
      int n=sc.nextInt();
      int r=sc.nextInt();
      int a=0;
      if (n<10){
        a=(100*(10-n))+r;
      }else{
        a=r;
      }
      System.out.println(a);
    }
}
