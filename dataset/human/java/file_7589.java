import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.util.*;

public class Main {
    static int ans = Integer.MAX_VALUE;
    public static void main(String[] args) throws Exception {
        BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
        StringTokenizer st = new StringTokenizer(br.readLine());

        int n = Integer.parseInt(st.nextToken());
        long k = Long.parseLong(st.nextToken());

        int[] arr = new int[n];
        st = new StringTokenizer(br.readLine());

        for (int i=0; i<n; i++)
            arr[i] = Integer.parseInt(st.nextToken());

        List<Integer> lst = new ArrayList<>();
        HashSet<Integer> vis = new HashSet<>();
        lst.add(1);
        vis.add(1);
        int i=0;
        int cycleStart = -1;
        for (; i<k; i++){
            int next = arr[lst.get(lst.size()-1)-1];
            if (vis.contains(next)){
                cycleStart = next;
                break;
            }
            vis.add(next);
            lst.add(next);
        }
        if (i==k){
            System.out.println(lst.get(lst.size()-1));
        }
        else{
            int j=0;
            for (; j<lst.size(); j++){
                if (lst.get(j)==cycleStart)
                    break;
                k--;
            }
            List<Integer> newLst = lst.subList(j,lst.size());
            System.out.println(newLst.get((int)(k%newLst.size())));
        }

    }
}
