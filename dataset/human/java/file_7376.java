import java.util.ArrayDeque;
import java.util.Deque;
import java.util.Scanner;

public class Main{
	public static void main(String[]args) {
		try(Scanner scan = new Scanner(System.in)){
			
			String S = scan.next();
			char[]s = new char[S.length()];
			s = S.toCharArray();
			
			Deque<Character> que = new ArrayDeque<Character>();
			//Deque<String> que = new ArrayDeque<String>();
			
			for(int i = 0;i<s.length;i++)que.addLast(s[i]);
			
			//System.out.println(que.getLast());
			
			
			while(true) {
			StringBuilder sb = new StringBuilder();
			
			for(int i = 0;i<5;i++)sb.append(que.removeLast());
			
			
			if(sb.toString().equals("maerd")||sb.toString().equals("esare")) {
				//sb.delete(0, 5);
			}else {
				sb.append(que.removeLast());
				if(sb.toString().equals("resare")) {
					//sb.delete(0, 6);
				}else{
					sb.append(que.removeLast());
					if(sb.toString().equals("remaerd")) {
						//sb.delete(0, 7);
					}else {
						System.out.println("NO");
						System.exit(0);
					}
				}
			}
			
			if(que.isEmpty())break;
			}
			
			System.out.println("YES");
			
			
			
			
			
			
			
			
		}
		
		
	}
		

}
