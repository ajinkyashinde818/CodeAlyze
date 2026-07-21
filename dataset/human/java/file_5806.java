import java.util.*;
class Main{
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		String str = sc.next();
		char[] data = new char[str.length()];
		for(int i=0; i<str.length(); i++){
			data[i] = str.charAt(i);
		}
		if(data[0]!=data[1]&&data[1]!=data[2]&&data[2]!=data[0]){
			System.out.println("Yes");
		}else{
			System.out.println("No");
		}
	}
}
