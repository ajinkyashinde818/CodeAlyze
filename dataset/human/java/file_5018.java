import java.util.LinkedList;
import java.util.List;
import java.util.Scanner;

public class Main {
	public static void main(String[] args){
		try(Scanner sc = new Scanner(System.in)) {
		
			String s = sc.next();
			int q = sc.nextInt();
			
			List<String> sList = new LinkedList<>();
			List<String> revList = new LinkedList<>();
			boolean isRev = false;
			sList.add(s);
			revList.add(new StringBuilder(s).reverse().toString());
			
			for(int i = 0 ; i < q ; i++ ) {
				int op = sc.nextInt();
				
				if ( op == 1 ) {
					isRev = !isRev;
				}
				else {
					int f = sc.nextInt();
					String c = sc.next();
					
					if ( isRev) {
						if ( f == 1 ) {
							//add rev head
							sList.add(c);
							revList.add(0,c);
						}
						else {
							sList.add(0,c);
							revList.add(c);
						}
					}
					else {
						if ( f == 1 ) {
							//add head
							sList.add(0, c);
							revList.add(c);
						}
						else {
							sList.add(c);
							revList.add(0,c);
						}
					}
					
				}
			}
		
			StringBuilder sb = new StringBuilder();					

			if (isRev) {
				for(String ss : revList) {
					sb.append(ss);
				}
			}
			else {
				for(String ss : sList) {
					sb.append(ss);
				}
			}

			System.out.println(sb.toString());
			
		}
	}
}
