import java.util.Arrays;
import java.util.Collections;
import java.util.Scanner;

public class Main {

	public static void main(String[] args) {
		// TODO 自動生成されたメソッド・スタブ
		Scanner scan = new Scanner(System.in);
		String s = scan.next();
		String t = scan.next();
		Character[] sc = new Character[s.length()];
		Character[] tc = new Character[t.length()];
		int length=Math.min(s.length(), t.length());
		for(int i=0;i<s.length();i++) {
			sc[i]=s.charAt(i);
		}
		for(int i=0;i<t.length();i++) {
			tc[i]=t.charAt(i);
		}
		Arrays.sort(sc);
		Arrays.sort(tc, Collections.reverseOrder());
		//System.out.println(Arrays.asList(sc));
		//System.out.println(Arrays.asList(tc));

/*
		boolean hantei = true;
		int count = 0;
		for(int i=0;i<length;i++) {
			int sci=sc[i];
		//	System.out.println(sci);
			int tci=tc[i];
		//	System.out.println(tci);
			if(sci<tci) {
				hantei=true;
				break;
			}else if(tci<sci) {
				hantei =false;
				break;
			}else {
				count++;
			}
		}
//System.out.println(count);
		//if(hantei==true) {
		//	if(tc.length<sc.length) {
			//	hantei=false;
		//	}
		//}
*/


		StringBuilder sortS = new StringBuilder();
		StringBuilder sortT = new StringBuilder();
		for(int i=0;i<s.length();i++) {
			sortS.append(sc[i]);
		}
		for(int i=0;i<t.length();i++) {
			sortT.append(tc[i]);
		}
	//	System.out.println(sortS);
	//	System.out.println(sortT);

		String[] zisyo =new String[2];
		zisyo[0]=sortS.toString();
		zisyo[1]=sortT.toString();
		Arrays.sort(zisyo);
	//	System.out.println(zisyo[0]);
	//	System.out.println(zisyo[1]);
boolean hantei = true;
		if(zisyo[0].equals(sortS.toString())) {
			hantei = true;
		}else {
			hantei =false;
		}



		if(hantei==true) {
			if(s.equals(t)) {
				System.out.println("No");
			}else {
			System.out.println("Yes");}
		}else {
			System.out.println("No");
		}


	}

}
