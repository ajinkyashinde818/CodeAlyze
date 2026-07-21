import java.util.Scanner;

public class Main{
	public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int i = sc.nextInt();

        String s = String.valueOf(i);
        String str = "9";

        if(s.indexOf(str) >= 0){
        	System.out.println("Yes");
        }else{
        	System.out.println("No");
        }
	}
}
