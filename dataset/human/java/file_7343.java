import java.util.*;
//import java.util.stream.Collectors;

public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		
		String s = sc.next();
		boolean b = true;
		while(s.length() != 0){
			if(s.endsWith("dream") || s.endsWith("erase")){
				s = s.substring(0, s.length() - 5);
			}else if(s.endsWith("eraser")){
				s = s.substring(0, s.length() - 6);
			}else if(s.endsWith("dreamer")){
				s = s.substring(0, s.length() - 7);
			}else{
				b = false;
				break;
			}
		}
		System.out.println(b ? "YES" : "NO");
	}
}
