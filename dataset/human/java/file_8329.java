import java.util.Scanner;

public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    long a = sc.nextLong();
    long b = sc.nextLong();
    long ans = 0;

    for(int i=1;i<=b;i++) {
    	if((a*i)%b==0) {
    		ans=a*i;
    		break;
    	}
    }
    System.out.println(ans);
  }
}
