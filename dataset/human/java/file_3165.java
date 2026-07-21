import java.util.Scanner;

class Main{
  public static void main(String[] args){
    Scanner sc=new Scanner(System.in);
    int a=sc.nextInt();
    int cnt9=0;
    while(a>0) {
    	if(a%10==9) {
    		cnt9++;
    	}
    	a/=10;
    }
    if(cnt9>0) {
    	System.out.println("Yes");
    }

    else{
    	System.out.println("No");
    }
  }
}
