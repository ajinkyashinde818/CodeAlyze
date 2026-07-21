import java.util.*;


public class Main {
	
	private void doit(){
		Scanner sc = new Scanner(System.in);
		while(sc.hasNext()){
			String s = sc.next();
			for(int i = 0; i < s.length(); i++){
				String temp = s.substring(i);
				if(temp.equals("FESTIVAL")){
					System.out.println(s.substring(0, i));
					break;
				}
			}
		}
	}



	private void debug(Object... o) {
		System.out.println("debug = " + Arrays.deepToString(o));
	}

	public static void main(String[] args) {
		new Main().doit();
	}

}
