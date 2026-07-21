import java.io.BufferedInputStream;
import java.io.IOException;
import java.util.*;

/**
 * Created by Harry on 5/10/20.
 */
public class Main {
    public static void main(String[] args) throws IOException {
        Scanner scanner = new Scanner(new BufferedInputStream(System.in));
        int n = scanner.nextInt();
        long k = scanner.nextLong();
        int[] A = new int[n+1];
        for(int i=1; i<=n; i++){
            A[i] = scanner.nextInt();
        }
        //{pos, pathIndex}
//        HashMap<Integer, Integer> map = new HashMap();
        int[] map = new int[n+1];
        Arrays.fill(map, -1);
        List<Integer> path = new ArrayList<>();
        int pos = 1;
        int cycleStartPos = -1;
        while(map[pos]==-1){
            map[pos] = path.size();
            path.add(pos);
            pos = A[pos];
            cycleStartPos = pos;
        }

//        System.out.println(path);
        if(path.size()>k){
            System.out.println(path.get((int)k));
        }
        else{
            int cycleStartIdx = map[cycleStartPos];
            int cycleLen = path.size()-cycleStartIdx;
            int beforeCycleLen = cycleStartIdx;
//            System.out.println(cycleStartIdx+","+cycleStartPos);
            k-=beforeCycleLen;
            k%=cycleLen;
            int index = beforeCycleLen+(int)k;
            System.out.println(path.get(index));
        }
    }
}
