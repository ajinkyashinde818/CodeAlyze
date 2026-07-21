import java.util.Scanner;
public class Main{
	static private Scanner scanner;
	static{
		scanner = new Scanner(System.in);
	}
	static public void main(String[] args){
		m2();
	}
	static public void m1(){
		String s = scanner.next();
	  	String result;
		if(s.endsWith("s")){
			result = s + "es";
		}else{
			result = s + "s";
		}
		System.out.println(result);

	}
	static public void m2(){
		int n = scanner.nextInt();
		boolean result = false;
		boolean[] ba = new boolean[]{false,false,false};
		String s;
		String[] sa;
		int d1;
		int d2;
		for(int i = 0; i < n; i++){
			//s = scanner.next();
			//sa = s.split(" ");
			d1 = scanner.nextInt();//Integer.parseInt(sa[0]);
			d2 = scanner.nextInt();//Integer.parseInt(sa[1]);
			if( d1 == d2 ){
				if( ba[0] == false ){
					ba[0] = true;
				}else{
					if( ba[1] == false ){
						ba[1] = true;
					}else{
						if( ba[2] == false ){
							ba[2] = true;
							result = true;
						}else{
						}
					}
				}
				
			}else{
				ba = new boolean[]{false,false,false};
			}

		}
		if(result == true){
			System.out.println("Yes");
		}else{
			System.out.println("No");
		}

	}
}
