import java.util.Scanner;

class Main{
	public static void main(String[] args) {
		Scanner sc=new Scanner(System.in);
		int rev = 0;
		String s=sc.next();
		int Q=sc.nextInt();
		int[] mae = new int[200001];
		int maecnt=0;
		int[] ato = new int[200001];
		int atocnt=0;
		for(int i=0; i<Q; i++) {
			int q = sc.nextInt();
			if( q ==1) {		//rev
				rev++;
			}
			else if(q ==2) {
				int fi = sc.nextInt();
				if(rev %2 == 0) {
					if(fi == 1) {
						mae[maecnt] = (sc.next()).charAt(0) - 'a';
						maecnt++;
					}
					else if(fi ==2) {
						ato[atocnt] = (sc.next()).charAt(0) - 'a';
						atocnt++;
					}
				}
				else {
					if(fi == 1) {
						ato[atocnt] = (sc.next()).charAt(0) - 'a';
						atocnt++;
					}
					else if(fi ==2) {
						mae[maecnt] = (sc.next()).charAt(0) - 'a';
						maecnt++;
					}
				}
			}
		}
		StringBuilder sb=new StringBuilder();
		if(rev % 2 == 0) {
			for(int i=maecnt -1; i>= 0 ; i--) {
				sb.append((char)(mae[i] + 'a'));
			}
			sb.append(s);
			for(int i=0; i< atocnt ; i++) {
				sb.append((char)(ato[i] + 'a'));
			}
		}
		else {
			for(int i=atocnt -1; i>= 0 ; i--) {
				sb.append((char)(ato[i] + 'a'));
			}
			StringBuffer str = new StringBuffer(s);
			sb.append(str.reverse().toString());
			for(int i=0; i< maecnt ; i++) {
				sb.append((char)(mae[i] + 'a'));
			}
		}
		pl(sb.toString());
	}
	public static void pl(Object o) {
		System.out.println(o);
	}

}
