import java.util.*;


public class Main {
	
	private void doit(){
		Scanner sc = new Scanner(System.in);
		while(sc.hasNext()){
			String s = sc.next();
			int n = s.length();
			char [] data = s.toCharArray();
			String t = s.replaceAll("x", "");
			char [] data2 = t.toCharArray();
			
			StringBuilder tt = new StringBuilder(t);
			if(! tt.reverse().toString().equals(t)){
				System.out.println(-1);
				continue;
			}
			int [] calc = new int[t.length() + 1];
			
			for(int i = 0, j = 0; i < n; i++){
				if(j == t.length()){
					calc[t.length()]++;
					continue;
				}
				if(data[i] == data2[j]){
					j++;
				}
				else{
					calc[j]++;
				}
			}
			
			int count = 0;
			for(int i = 0; i <= t.length() / 2; i++){
				int ind = t.length()-i;
				count += Math.abs(calc[i]-calc[ind]);
			}
			System.out.println(count);
			
			
		}
	}



	private void debug(Object... o) {
		System.out.println("debug = " + Arrays.deepToString(o));
	}

	public static void main(String[] args) {
		new Main().doit();
	}

}
