import java.util.Scanner;
public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);

    int a = sc.nextInt();
    int b = sc.nextInt();
    int k = sc.nextInt();
    int r = 1;
    int cnt = 0;


    for(int i = 100; i > 0; i--) {
    	if(k > cnt) {
    		if(a % i == 0 && b % i == 0) {
    			r = i;
    			cnt++;
    		}
    	}
    	else {
    		break;
    	}
    }
    System.out.println(r);
  }
}
