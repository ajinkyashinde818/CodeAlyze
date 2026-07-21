import java.util.*;

public class Main {
    public static void main(String[] args) {
        Scanner scan = new Scanner(System.in);

        int K = Integer.parseInt(scan.next());
        int N = Integer.parseInt(scan.next());
        int min = 0;

        List<Integer> A = new ArrayList<>();
        List<Integer> dist = new ArrayList<>();

        for(int i=0; i<N; i++)
        {
            A.add(Integer.parseInt(scan.next()));
        }

        scan.close();
        
        for(int i=0; i<N; i++)
        {
            if(i<N-1)
            {
                dist.add(A.get(i+1) - A.get(i));
            }else{
                dist.add(K-A.get(i) + A.get(0));
            }
        }

        Collections.sort(dist);
        //System.out.println(dist);

        for(int i=0; i<N-1; i++)
        {
            min += dist.get(i);
        }
        System.out.println(min);
    }
}
