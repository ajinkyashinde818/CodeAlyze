import java.util.*;
public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int a = sc.nextInt();
        int b = sc.nextInt();                              
		System.out.println(b+Math.max(0,100*(10-a)));
	}
}
