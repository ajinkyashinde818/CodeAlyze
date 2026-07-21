//30分

import java.util.Scanner;
public class Main {

	public static void main(String[] args) {

		Scanner sc = new Scanner(System.in);

		String s = sc.next();

		int l = s.length();

		char[] c = new char[l];

		for(int i=0;i<l;i++) {

			c[i] = s.charAt(i);

		}

		int rec = l-1;

		boolean flag = false;

		while(rec>=0) {

			String ss = "";

			if(c[rec] == 'r') {

				for(int i=0;i<7;i++) {

					if(rec-i>=0) {

						ss += c[rec-i];

					}else {

						flag = true;

						break;
					}

					if(i==5 && ss.equals("resare") ) {

						rec = rec-6;

						break;

					}

					if(i==6 && ss.equals("remaerd")) {

						rec = rec-7;

						break;

					}

					if(i==6) flag = true;

				}
			}else {

				for(int i=0;i<5;i++) {

					if(rec-i>=0) {

						ss += c[rec-i];

					}else {

						flag = true;

						break;
					}
				}

				if(ss.equals("maerd") || ss.equals("esare"))  rec = rec-5;
			}

			if(flag == true) {

				System.out.println("NO");

				break;
			}
		}

		if(flag == false) System.out.println("YES");

	}

}
