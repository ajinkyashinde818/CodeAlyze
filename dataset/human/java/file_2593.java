import java.util.*;

public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		String s = sc.next();
		char[] s_char = s.toCharArray();
		Arrays.sort(s_char);
		
		String t = sc.next();
		char[] t_char = t.toCharArray();
		Arrays.sort(t_char);
		for(int i = 0 ; i < t_char.length/2 ; i ++){
			char temp = t_char[t_char.length - i - 1];
			t_char[t_char.length - i - 1] = t_char[i];
			t_char[i] = temp;
		}
		
		//determin all characters 
		boolean loopFlag = false;
		
		
		boolean result = false;
		
		for(int i = 0 ;i < Math.min(s_char.length,t_char.length);i ++ ){
			if(s_char[i] != t_char[i]){
				result = s_char[i] < t_char[i];
				break;
			}
			loopFlag = (i == Math.min(s_char.length,s_char.length) - 1);
		}
		
		if(loopFlag){
			result = (s_char.length < t_char.length);
		}
		
		System.out.println( result ? "Yes" : "No" );
	}
}
