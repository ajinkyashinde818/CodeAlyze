import java.util.*;
 
public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		int R = sc.nextInt();
		int ans = 0;
		
		if(N<10){
			ans = R+100*(10-N);
        }else {
			ans = R;
        }
		System.out.println(ans);
    }
}
