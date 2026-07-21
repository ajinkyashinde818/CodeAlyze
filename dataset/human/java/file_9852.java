import java.util.*;

public class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
    	int n = sc.nextInt();
        int m = sc.nextInt();
        int x = sc.nextInt();
        int minCost = Integer.MAX_VALUE;
        int[] costs = new int[n];
        int[][] knowledgeBooster = new int[n][m];
        int[] currentKnowledge = new int[m];
        int currentCost = 0;
        
        for(int i = 0; i < n; i++) {
        	costs[i] = sc.nextInt();
        	for(int j = 0; j < m; j++) {
        		knowledgeBooster[i][j] = sc.nextInt();
        	}
        }
        int maskLimit = 1 << n;
        for(int mask = 0; mask < maskLimit; mask++) {
        	currentCost = 0;
        	Arrays.fill(currentKnowledge, 0);
        	for(int i = 0; i < n; i++) {
        		if(((mask >> i) & 1) == 1) {
        			currentCost += costs[i];
        			for(int j = 0; j < m; j++) {
        				currentKnowledge[j] += knowledgeBooster[i][j];
        			}
        		}
        	}
        	boolean knowledgeSatisfied = true;
        	for(int i = 0; i < m; i++) {
        		if(currentKnowledge[i] < x) {
        			knowledgeSatisfied = false;
        			break;
        		}
        	}
        	if(knowledgeSatisfied)
        		minCost = Math.min(currentCost, minCost);
        }
        System.out.println(minCost == Integer.MAX_VALUE? "-1": minCost);

    }
    
}
