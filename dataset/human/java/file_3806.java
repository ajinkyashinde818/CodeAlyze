import java.util.Scanner;
import java.util.Arrays;
public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		int y=0;
		int t=s.length()-1;
		int ans=0;
		while(t>y){
			if(s.charAt(y)==s.charAt(t)){
				t--;
				y++;
			}else if(s.charAt(y)=='x' || s.charAt(t)=='x'){
				ans++;
				if(s.charAt(y)=='x'){
					y++;
				}else{
					t--;
				}
			}else{
				System.out.println(-1);
				return;
			}
		}
		System.out.println(ans);
	}
}
