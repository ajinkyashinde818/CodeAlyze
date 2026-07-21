import java.util.Scanner;
public class Main {

	public static void main(String[] args) {
		Scanner stdIn = new Scanner(System.in);
		
		/*<考察>
		 * dream を a
		 * dreamer を b
		 * erase を c
		 * eraser を d とおく。
		 * 
		 * s と a,b,c,dを何度も比較する 4 *10^5で十分間に合う
		 * 比較するときに文字列がずれるためできないのでは。。。？
		 * 前から比較するとdream,dreamerのどっちで切っていいか分からなくなる、このような関係をprefixという。
		 * 
		 * dream,dreamer,erase,eraser以外の異物が入っているときに絶対不可能であるため、
		 * 変な文字が入ってないか確認するか？
		 * 		
		*/
		
		/*String s = stdIn.next();
		
		if(!(s.contains("dream") || s.contains("dreamer") || s.contains("erase") || s.contains("eraser")) ) {
			System.out.println("NO");
		}else {
			System.out.println("YES");
		}
		*/
		
//		String[] divide = new String[] {"dream","dreamer","erase","eraser"};
		StringBuilder[] sb = new StringBuilder[] {new StringBuilder("dream"),new StringBuilder("dreamer"),new StringBuilder("erase"),new StringBuilder("eraser")};
		
		for(int i = 0; i < sb.length; i++) {
			sb[i] = sb[i].reverse();
		}
		
		String s2 = stdIn.next();
		
		StringBuilder s1 = new StringBuilder(s2);
		String s = s1.reverse().toString();
		
		
		boolean flag = true;
		
		
	Outer:	for(int i = 0; i < s.length();) {
			boolean flag2 = false; //4個の文字列のうちあてはまるものはあるか
			
			
			
			if(s.length() - i == 5) {
				if(s.substring(i,s.length()).equals("maerd") || s.substring(i,s.length()).equals("esare")) {
					flag2 = true;
					break Outer;
				}
			}
			if(s.length() - i == 6) {
				if(s.substring(i,s.length()).equals("resare")){
					flag2 = true;
					break Outer;
				}
			}
		
			
			for(int j = 0; j < 4; j++) {
				String d = sb[j].toString();
				
	
				if(s.substring(i,i+d.length()).equals(d)) { //あてはまった
					flag2 = true;
					i += d.length();
					continue Outer;
				}
			}
			
			
			
			
			
			if(!flag2) {
				flag = false;
				break;
			}
		}
		
		if(flag) {
			System.out.println("YES");
		}else {
			System.out.println("NO");
		}
		
	}

}
