import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
			String S = sc.next();
		sc.close();


		StringBuffer sb = new StringBuffer(S);
		String T = sb.reverse().toString();

		//System.out.println(T);

		boolean flag = true;
		for(int i = 0 ; i < T.length() ; i++){
			if(i+5 <=T.length() && (T.substring(i, i+5).equals("maerd") ||T.substring(i, i+5).equals("esare"))){
				//System.out.println(T.substring(i, i+5));
				i +=4;

			}
			else if(i+6<=T.length() && T.substring(i, i+6).equals("resare")){
				//System.out.println(T.substring(i, i+6));
				i += 5;

			}
			else if(i+7<=T.length() && T.substring(i, i+7).equals("remaerd")){
				//System.out.println(T.substring(i, i+7));
				i += 6;

			}

			else{
				flag = false;
				break;
			}
		}

		if(flag){
			System.out.println("YES");
		}
		else{
			System.out.println("NO");
		}
	}
}
