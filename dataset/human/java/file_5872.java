import java.util.*;

class Main{
	
	public static void main(String args[]){

		Scanner sc = new Scanner(System.in);

		String st = sc.next();
		ArrayList<String> arr = new ArrayList<>();
		arr.add("a");
		arr.add("b");
		arr.add("c");

		for(int n=0;n<3;n++){
			String ch = String.valueOf(st.charAt(n));
			if(arr.indexOf(ch) != -1) arr.remove(arr.indexOf(ch));
		}

		if(arr.size()==0) System.out.println("Yes");
		else System.out.println("No");
	}
}
