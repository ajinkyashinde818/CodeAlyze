import java.util.*;

public class Main {
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
        int num = sc.nextInt();
        
        String ans = "";
        
        if(num < 1200){
            ans = "ABC";
        }else{
            ans = "ARC";
        }
        
        System.out.println(ans);
	}
}
