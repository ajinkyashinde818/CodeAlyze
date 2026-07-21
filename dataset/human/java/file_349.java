import java.util.*;

public class Main {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int xs = sc.nextInt();
		int ys = sc.nextInt();
		int xt = sc.nextInt();
		int yt = sc.nextInt();
		int n = sc.nextInt();
		int[] xArr = new int[n + 2];
		int[] yArr = new int[n + 2];
		int[] rArr = new int[n + 2];
		for (int i = 0; i < n; i++) {
		    xArr[i] = sc.nextInt();
		    yArr[i] = sc.nextInt();
		    rArr[i] = sc.nextInt();
		}
		xArr[n] = xs;
		yArr[n] = ys;
		xArr[n + 1] = xt;
		yArr[n + 1] = yt;
		double[][] matrix = new double[n + 2][n + 2];
		for (int i = 0; i < n + 1; i++) {
		    for (int j = i + 1; j < n + 2; j++) {
		        double dist = getDist(xArr[i], yArr[i], rArr[i], xArr[j], yArr[j], rArr[j]);
		        matrix[i][j] = dist;
		        matrix[j][i] = dist;
		    }
		}
		PriorityQueue<Path> queue = new PriorityQueue<>();
		queue.add(new Path(n, 0));
		double[] costs = new double[n + 2];
		Arrays.fill(costs, Double.MAX_VALUE);
		while (queue.size() > 0) {
		    Path p = queue.poll();
		    if (costs[p.idx] <= p.value) {
		        continue;
		    }
		    costs[p.idx] = p.value;
		    for (int i = 0; i < n + 2; i++) {
		        if (costs[i] != Double.MAX_VALUE) {
		            continue;
		        }
		        queue.add(new Path(i, p.value + matrix[p.idx][i]));
		    }
		}

	    System.out.println(java.math.BigDecimal.valueOf(costs[n + 1]).toPlainString());
    }
    
    static double getDist(int x1, int y1, int r1, int x2, int y2, int r2) {
        return Math.max(Math.sqrt(Math.pow(x1 - x2, 2) + Math.pow(y1 - y2, 2)) - r1 - r2, 0);
    }
    
    static class Path implements Comparable<Path> {
        int idx;
        double value;

        public Path(int idx, double value) {
            this.idx = idx;
            this.value = value;
       }
        
        public int compareTo(Path another) {
            if (value == another.value) {
                return 0;
            } else if (value < another.value) {
                return -1;
            } else {
                return 1;
            }
        }
        
        public String toString() {
            return idx + ":" + value;
        }
    }
}
