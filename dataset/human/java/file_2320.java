import java.util.*;
public class Main {
	public static ArrayList<Integer> list = new ArrayList<Integer>();
	public static String[] LIST = new String[] {"a","b","c","d","e","f","g","h","i","j","k",
								"l","m","n","o","p","q","r","s","t","u","v","w","x","y","z",
								"A","B","C","D","E","F","G","H","I","J","K","L","M","N","O",
								"P","Q","R","S","T","U","V","W","X","Y","Z"}; 
	public static void main(String[] args) {
		Scanner stdIn = new Scanner(System.in);
		while(true) {
			int n = stdIn.nextInt();
			if(n == 0) break;
			int[] key = new int[n];
			for(int i = 0; i < n; i++) {
				key[i] = stdIn.nextInt();
			}
			String list = stdIn.next();
			int c = 0;
			for(int i = 0; i < list.length(); i++) {
				int p = key[c % key.length];
				String a = list.substring(i, i+1);
				for(int j = 0; j < LIST.length; j++) {
					if(a.equals(LIST[j])) {
						int ck = (j - p) % LIST.length;
						while(ck < 0) {
							ck += LIST.length;
						}
						
						System.out.print(LIST[ck]);
						break;
					}
				}
				c++;
 			}
			System.out.println();
			
		}
		
	}
}
