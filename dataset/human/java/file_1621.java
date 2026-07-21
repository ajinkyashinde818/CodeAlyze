import java.util.*;

class Main {
	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int N = sc.nextInt();
		String S = sc.next();
		int[] cnt = new int[26];
		for (int i=0;i<N;i++) {
			if (S.charAt(i)=='a') {
				cnt[0]++;
			}else if(S.charAt(i)=='b') {
				cnt[1]++;
			}else if(S.charAt(i)=='c') {
				cnt[2]++;
			}else if(S.charAt(i)=='d') {
				cnt[3]++;
			}else if(S.charAt(i)=='e') {
				cnt[4]++;
			}else if(S.charAt(i)=='f') {
				cnt[5]++;
			}else if(S.charAt(i)=='g') {
				cnt[6]++;
			}else if(S.charAt(i)=='h') {
				cnt[7]++;
			}else if(S.charAt(i)=='i') {
				cnt[8]++;
			}else if(S.charAt(i)=='j') {
				cnt[9]++;
			}else if(S.charAt(i)=='k') {
				cnt[10]++;
			}else if(S.charAt(i)=='l') {
				cnt[11]++;
			}else if(S.charAt(i)=='m') {
				cnt[12]++;
			}else if(S.charAt(i)=='n') {
				cnt[13]++;
			}else if(S.charAt(i)=='o') {
				cnt[14]++;
			}else if(S.charAt(i)=='p') {
				cnt[15]++;
			}else if(S.charAt(i)=='q') {
				cnt[16]++;
			}else if(S.charAt(i)=='r') {
				cnt[17]++;
			}else if(S.charAt(i)=='s') {
				cnt[18]++;
			}else if(S.charAt(i)=='t') {
				cnt[19]++;
			}else if(S.charAt(i)=='u') {
				cnt[20]++;
			}else if(S.charAt(i)=='v') {
				cnt[21]++;
			}else if(S.charAt(i)=='w') {
				cnt[22]++;
			}else if(S.charAt(i)=='x') {
				cnt[23]++;
			}else if(S.charAt(i)=='y') {
				cnt[24]++;
			}else if(S.charAt(i)=='z') {
				cnt[25]++;
			}
		}
		long sum = (long)0;
		for (int i=0;i<26;i++) {
			if (cnt[i]>=1) {
				sum+=(sum+1)*cnt[i];
			}
			if (sum>1000000007) {
				sum%=1000000007;
			}
		}
		System.out.println(sum%1000000007);
	}
}
