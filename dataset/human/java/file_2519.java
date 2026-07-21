import  java.util.Scanner;


public class Main {
	Scanner sc;
	private int parse( String mcxi ){
		boolean isNumEntered = false;
		int mk = 0;
		int ck = 0;
		int xk = 0;
		int ik = 0;
		int cur = 0;
		char[] cstr = mcxi.toCharArray();
		for( int i = 0; i < cstr.length; i++ ){
			switch( cstr[ i ] ){
				case 'm':
					mk = cur;
					if( !isNumEntered ){ mk = 1; }
					isNumEntered = false;
					break;
				case 'c':
					ck = cur;
					if( !isNumEntered ){ ck = 1; }
					isNumEntered = false;
					break;
				case 'x':
					xk = cur;
					if( !isNumEntered ){ xk = 1; }
					isNumEntered = false;
					break;
				case 'i':
					ik = cur;
					if( !isNumEntered ){ ik = 1; }
					isNumEntered = false;
					break;
				default:
					cur = cstr[ i ] - '0';
					isNumEntered = true;
					break;
			}
		}
		return mk * 1000 + ck * 100 + xk * 10 + ik;
	}

	private String getMcxi( int in ){
		int mk = in / 1000;
		in %= 1000;
		int ck = in / 100;
		in %= 100;
		int xk = in / 10;
		in %= 10;
		int ik = in;
		String r = "";
		if( mk >= 2 ){ r += mk; }
		if( mk >= 1 ){ r += "m"; }
		if( ck >= 2 ){ r += ck; }
		if( ck >= 1 ){ r += "c"; }
		if( xk >= 2 ){ r += xk; }
		if( xk >= 1 ){ r += "x"; }
		if( ik >= 2 ){ r += ik; }
		if( ik >= 1 ){ r += "i"; }
		return r;
	}

	private void run(){
		sc = new Scanner( System.in );
		int n = sc.nextInt();
		for( int i = 0; i < n; i++ ){
			System.out.println( getMcxi ( parse( sc.next() ) + parse( sc.next() ) ) );
		}
	}
	public static void main( String[] args ){
		new Main().run();
	}
}
