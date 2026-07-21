import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        //コード
    	Scanner sc = new Scanner(System.in);
//    	File file = new File("src/in.txt");
//    	Scanner sc = new Scanner(file);
    	int N = sc.nextInt();
    	long K = sc.nextLong();
    	int[] A = new int[N+1];
    	for(int i=1;i<=N;i++) {
    		A[i] = sc.nextInt();
    	}

    	int now = 1;
    	int count = 0;
    	int[] visited_town_list = new int[N+1];

    	boolean loopnotfound = true;

    	int firstvisit = 0;
    	int secondvisit = 0;

    	while(loopnotfound) {
    		count = count + 1;
    		int next = A[now];
    		if(visited_town_list[next] == 0) {
        		visited_town_list[next] = count;
        		now = next;
    		}
    		else {
    			firstvisit = visited_town_list[next];
    			secondvisit = count;
    			loopnotfound = false;
    		}
    	}
//    	System.out.println("first:"+firstvisit);
//    	System.out.println("second:"+secondvisit);
    	int ans = 0;
    	if(K>=firstvisit) {
        	int q = (int) ((K-firstvisit+1)%(secondvisit-firstvisit));
        	for(int i =1;i<N+1;i++) {
        		//ループに入る前のものは無視
        		if(visited_town_list[i]>=firstvisit) {
        			//
        			if((visited_town_list[i]-firstvisit+1)%(secondvisit-firstvisit)==q) {
        				ans = i;
        			}
        		}
        	}

    	} else {
    		for(int i=1;i<N+1;i++) {
    			if(visited_town_list[i]==K) {
    				ans = i;
    			}
    		}
    	}
    	System.out.println(ans);
    }
}
