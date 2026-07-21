import java.util.*;

class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        int M = sc.nextInt();
        HashSet<Integer>[] map = new HashSet[N+1];
        for(int i=0;i<=N;i++) map[i] = new HashSet<>();
        for(int i=1;i<=M;i++){
            int a = sc.nextInt();
            int b = sc.nextInt();
            map[a].add(b);
        }
        String ans = "IMPOSSIBLE";
        if(map[1].size()>0){
            for(Integer w:map[1]){
                if(map[w].contains(N)) {
                    ans = "POSSIBLE";
                    break;
                }
            }
        }
        System.out.println(ans);
    }
}
