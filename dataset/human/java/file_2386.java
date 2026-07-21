import java.util.*;

// DDCC 2017-D
// http://ddcc2017-qual.contest.atcoder.jp/tasks/ddcc2017_qual_d	

public class Main {

	public static void main (String[] args) throws InterruptedException {
		Scanner in = new Scanner(System.in);
		String s = in.next();
		int index = s.lastIndexOf("FESTIVAL");
		System.out.println(s.substring(0, index));
	}
}
