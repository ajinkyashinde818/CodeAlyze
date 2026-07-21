import java.util.Scanner;

public class Main{
	public static void main(String[] args){
		Scanner sc = new Scanner(System.in);

		String s = sc.next();
		String t = sc.next();

		char[] cs = s.toCharArray();
		char[] ct = t.toCharArray();

		sort(cs);
		rsort(ct);
		
//		printArray(cs);
//		printArray(ct);
		
		s = new String(cs);
		t = new String(ct);


		System.out.println(s.compareTo(t) < 0 ? "Yes" : "No");
	}
	
	public static void sort(char[] a){
		
		for(int i = 1 ; i < a.length ; ++i){
			char c = a[i];
			int j = i-1;
			while(j >= 0 && Character.compare(c , a[j]) < 0){
				a[j+1] = a[j];
				--j;
			}
			
			a[j+1] = c;
		}
	}
	
	public static void rsort(char[] a){
		
		for(int i = a.length -1 ; i >= 0 ; --i){
			char c = a[i];
			int j = i+1;
			while(j < a.length && Character.compare(c , a[j]) < 0){
				a[j-1] = a[j];
				++j;
			}
			a[j -1] = c;
		}
	}
	
	public static void printArray(char[] a){
		
		StringBuilder s = new StringBuilder();
		
		for(char c : a){
			s.append(c);
		}
		s.append("\n");
		System.out.println(s);
	}
}
