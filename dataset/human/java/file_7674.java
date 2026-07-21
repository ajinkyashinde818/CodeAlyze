import java.util.*;

public class Main {
    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long k = sc.nextLong();
        int[] teleportation = new int[n];
        long stepsBeforeCycle = 0;
        int slow, fast;

        for(int i = 0; i < n; i++)
        	teleportation[i] = sc.nextInt() - 1;
        slow = fast = 0;

        while(true) {
        	slow = teleportation[slow];
        	fast = teleportation[teleportation[fast]];
        	if(slow == fast)
        		break;
        }
        int loopLen = 1;
        while(teleportation[fast] != slow) {
        	fast = teleportation[fast];
        	loopLen++;
        }

        fast = slow;
        slow = 0;
        while(slow != fast) {
        	slow = teleportation[slow];
        	fast = teleportation[fast];
        	stepsBeforeCycle++;
        }

        if(k <= stepsBeforeCycle) {
        	// slow = 0;
        	// while(k > 0) {
        	// 	slow = teleportation[slow];
        	// 	k--;
        	// }
        	// System.out.println(slow + 1);
        	// return;
        	System.out.println(solve(teleportation, k, 0));
        }
        else {
        	k -= stepsBeforeCycle;
        	k %= loopLen;
        	System.out.println(solve(teleportation, k, slow));
        	// while(k > 0) {
        	// 	slow = teleportation[slow];
        	// 	k--;
        	// }
        	// System.out.println(slow + 1);
        }

    }
    public static int solve(int[] teleportation, long k, int slow) {
    	while(k > 0) {
        		slow = teleportation[slow];
        		k--;
        	}
        return slow + 1;
    }
}
