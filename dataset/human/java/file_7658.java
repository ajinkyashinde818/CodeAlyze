import java.util.*;

class Main{

    public static void main(String args[]) {
        Scanner sc = new Scanner(System.in);
        Integer n = sc.nextInt();
        Long k = sc.nextLong();
        int[] a = new int[n+1];
        for(int i=1;i<=n;i++){
            a[i] = sc.nextInt();
        }

        int[] check = new int[n+1];
        int now = 1;
        List<Integer> path = new ArrayList<>();
        while(true){
            path.add(now);
            if(check[now]==1)break;
            if(path.size()==k+1){
                System.out.println(now);
                return;
            }
            check[now] = 1;
            now = a[now];
        }

        Long count = 0L;
        for(Integer p : path){
            if(p==now)break;
            count++;
        }

        Long loop_size = path.size() - count - 1L;

        
        long rest = (k-count)%loop_size;
        System.out.println(path.get((int)(count+rest)));

    }
}
