import java.util.Scanner;
//import java.util.Arrays;
public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);
		String a = sc.next();
		String b = sc.next();
		String result = "";
		if(a.equals(b)){
			result += "=";
		}else{
			String[] alp = {"A", "B", "C", "D", "E", "F"};
			for(int i=0; i<alp.length; i++){
				if(alp[i].equals(a)){
					result += "<";
					break;
				}else if(alp[i].equals(b)){
					result += ">";
					break;
				}
			}
		}
		System.out.println(result);
	}
}
