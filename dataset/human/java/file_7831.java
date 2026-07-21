import java.util.*;
public class Main {
    public static void main(String args[]){
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        long K = sc.nextLong();
        Map<Integer, Integer> mp = new HashMap<>();
        for(int i=0;i<N;i++){
            int A = sc.nextInt()-1;
            mp.put(i, A);
        }
        Set<Integer> visited = new HashSet<>();
        int now=0;
        List<Integer> arr = new ArrayList<>();
        while(true){
            if(visited.contains(now)){
                break;
            }
            visited.add(now);
            arr.add(now);
            now = mp.get(now);
        }
//        System.out.println(arr);
//        System.out.println(arr.indexOf(now));
        int remain = arr.indexOf(now);
        int ans=0;
        if(K < remain){
            ans = arr.get((int)K);
        }else{
            long res = ((K-(long)remain) % (long)(arr.size()-remain)) + (long)remain;
            ans = arr.get((int)res);
        }
        System.out.println(ans+1);
    }

}
