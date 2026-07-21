import java.util.*;
public class Main {

	public static void main(String[] args) {
		Scanner sc = new Scanner(System.in);
		int n = sc.nextInt();
		String s = sc.next();
		String[] S = s.split("");
		int[] alphabetnum = new int[26];
		long answer = 1;
		for(int i = 0; i < n; i++) {
			if(S[i].equals("a")) alphabetnum[0] += 1;
			if(S[i].equals("b")) alphabetnum[1] += 1;
			if(S[i].equals("c")) alphabetnum[2] += 1;
			if(S[i].equals("d")) alphabetnum[3] += 1;
			if(S[i].equals("e")) alphabetnum[4] += 1;
			if(S[i].equals("f")) alphabetnum[5] += 1;
			if(S[i].equals("g")) alphabetnum[6] += 1;
			if(S[i].equals("h")) alphabetnum[7] += 1;
			if(S[i].equals("i")) alphabetnum[8] += 1;
			if(S[i].equals("j")) alphabetnum[9] += 1;
			if(S[i].equals("k")) alphabetnum[10] += 1;
			if(S[i].equals("l")) alphabetnum[11] += 1;
			if(S[i].equals("m")) alphabetnum[12] += 1;
			if(S[i].equals("n")) alphabetnum[13] += 1;
			if(S[i].equals("o")) alphabetnum[14] += 1;
			if(S[i].equals("p")) alphabetnum[15] += 1;
			if(S[i].equals("q")) alphabetnum[16] += 1;
			if(S[i].equals("r")) alphabetnum[17] += 1;
			if(S[i].equals("s")) alphabetnum[18] += 1;
			if(S[i].equals("t")) alphabetnum[19] += 1;
			if(S[i].equals("u")) alphabetnum[20] += 1;
			if(S[i].equals("v")) alphabetnum[21] += 1;
			if(S[i].equals("w")) alphabetnum[22] += 1;
			if(S[i].equals("x")) alphabetnum[23] += 1;
			if(S[i].equals("y")) alphabetnum[24] += 1;
			if(S[i].equals("z")) alphabetnum[25] += 1;
		}
		for(int i = 0; i < 26; i++) {
			answer *= (alphabetnum[i]+1);
			answer %= 1000000007;
		}
		answer -= 1;
		System.out.println(answer);
	}

}
