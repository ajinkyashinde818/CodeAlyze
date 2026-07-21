import java.util.Scanner;
public class Main {

	public static void main(String[] args) {
		Scanner stdIn = new Scanner(System.in);
		
		String s = stdIn.next();
		int q = stdIn.nextInt();
		
		String t = ""; //反転する文字列
		
		StringBuffer sbs = new StringBuffer(s); //文字列sを最初に格納
		StringBuffer sbt = new StringBuffer(); //文字列tを最初に格納
		
		StringBuffer tmp;
		
		for(int i = 0; i < q; i++) {
			if(stdIn.nextInt() == 1) { //反転作業
				tmp = sbs;
				sbs = sbt;
				sbt = tmp;
			}else {
				if(stdIn.nextInt() == 1) {
					sbt.append(stdIn.next());
				}else {
					sbs.append(stdIn.next());
				}
				
			}
			
			
			
			
			
		}
		
		System.out.println(sbt.reverse().append(sbs).toString());
		
		
		
		
	}

}
