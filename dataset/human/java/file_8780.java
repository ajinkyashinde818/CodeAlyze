import java.util.Scanner;

public class Main{
  public static void main(String[] args){
    Scanner sc = new Scanner(System.in);
    int a = sc.nextInt();
    int b = sc.nextInt();
    int k = sc.nextInt();
    sc.close();
    int count = 0;
    int ans = 0;
    for(int i=100;count<k;i--) {
    	if((a%i==0) && (b%i==0)) {
    		ans = i;
    		count++;
    	}
    }
    System.out.println(ans);
    
  }
}
