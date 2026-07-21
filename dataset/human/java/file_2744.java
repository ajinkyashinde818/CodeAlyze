import java.util.ArrayList;
import java.util.Collections;
import java.util.Comparator;
import java.util.Scanner;

class Main{

	static int[] p;
	static	int N ;
	static	int M ;


	public static void main(String[] args) {


		Scanner scanner = new Scanner(System.in);
		//N = scanner.nextInt();
		//M = scanner.nextInt();

		String s = scanner.next();
		String t = scanner.next();

		ArrayList<String> slist = new ArrayList<String>();
		ArrayList<String> tlist = new ArrayList<String>();

		for(int i = 0;i < s.length();i++){
			slist.add(s.substring(i, i+1));
		}
		for(int i = 0;i < t.length();i++){
			tlist.add(t.substring(i, i+1));
		}
		Collections.sort(slist);
		Collections.sort(tlist,Comparator.reverseOrder());

		StringBuilder sbs = new StringBuilder();
		for(int i = 0;i < s.length();i++){
			sbs.append(slist.get(i));
		}
		s = sbs.toString();
		
		StringBuilder sbt = new StringBuilder();
		for(int i = 0;i < t.length();i++){
			sbt.append(tlist.get(i));
		}
		t =sbt.toString();
		
		boolean flags = true;
		boolean flagt = true;

		for(int i = 0;i < s.length()-1;i++){
			if(flags){
				if(!(s.substring(i,i+1).equals(s.substring(i+1,i+2)))){
					flags = false;
				}
			}
		}
		for(int i = 0;i < t.length()-1;i++){
			if(flagt){
				if(!(t.substring(i,i+1).equals(t.substring(i+1,i+2)))){
					flagt = false;
				}
			}
		}


		


		if(s.substring(0,1).equals(t.substring(0,1)) &&  flags && flagt){

			if(s.length() >= t.length()){
				System.out.println("No");
			}else{
				System.out.println("Yes");

			}
			return;
		}




		if(t.compareTo(s) >= 1){
			System.out.println("Yes");
		}else{
			System.out.println("No");

		}

	}


}

class Pair implements Comparable{
	int from;
	int middle;
	int end;
	@Override
	public int compareTo(Object other) {
		Pair otherpair = (Pair)other;

		return end - otherpair.end;
	}
}
