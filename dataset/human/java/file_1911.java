import java.util.Scanner;

public class Main {
	public static void main(String[] args) {
		Scanner scanner = new Scanner(System.in);
		String[] conf = scanner.nextLine().split(" ");
		int numPoints = Integer.parseInt(conf[0]);
		long goal = Long.parseLong(conf[1]);
		int[] numProblems = new int[numPoints + 1];
		int[] achievablePoints = new int[numPoints + 1];
		int[] solved = new int[numPoints + 1];
		for(int pIdx = 1; pIdx <= numPoints; pIdx++) solved[pIdx] = (int) Math.pow(2, pIdx - 1);

		for(int pIdx = 1; pIdx <= numPoints; pIdx++) {
			String[] inputs = scanner.nextLine().split(" ");
			numProblems[pIdx] = Integer.parseInt(inputs[0]);
			achievablePoints[pIdx] = numProblems[pIdx] * pIdx * 100 + Integer.parseInt(inputs[1]);
		}

		int minNumSolved = Integer.MAX_VALUE;
		int maxSolvePlan = (int) Math.pow(2, numPoints) - 1;
LOOP:	for(int solvePlan = 0; solvePlan <= maxSolvePlan; solvePlan++) {
			long tmpTotalPoint = 0L;
			int tmpNumSolved = 0;
			for(int pIdx = 1; pIdx <= numPoints; pIdx++) {
				if((solved[pIdx] & solvePlan) != 0) {
					tmpTotalPoint += achievablePoints[pIdx];
					tmpNumSolved += numProblems[pIdx];
				}
			}
			long remainder = goal - tmpTotalPoint;
			for(int pIdx = numPoints; remainder > 0L && pIdx >= 1; pIdx--) {
				if((solved[pIdx] & solvePlan) == 0) {
					int tmpNumPartiallySolved = (int) ((remainder - 1L) / (pIdx * 100)) + 1;
					if(tmpNumPartiallySolved >= numProblems[pIdx]) continue LOOP;
					tmpNumSolved += tmpNumPartiallySolved;
					tmpTotalPoint += tmpNumPartiallySolved * pIdx * 100;
					break;
				}
			}
			if(minNumSolved > tmpNumSolved) minNumSolved = tmpNumSolved;
		}

		System.out.println(minNumSolved);
	}
}
