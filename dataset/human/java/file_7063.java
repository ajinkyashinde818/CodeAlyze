import java.util.*;

public class Main {
    public static void main(String[] args)
    {
        Scanner s = new Scanner(System.in);
        StringTokenizer st = new StringTokenizer(s.nextLine());
        int K = Integer.parseInt(st.nextToken());
        int N = Integer.parseInt(st.nextToken());
        st = new StringTokenizer(s.nextLine());
        int[] houses = new int[N+1];
        for(int i=0;i<N;i++)
        {
            houses[i] = Integer.parseInt(st.nextToken());
        }
        houses[N] = K + houses[0];
        int distance = Integer.MAX_VALUE;
        for(int i=0;i<N;i++)
        {
            int start = houses[i];
            int end = houses[i+1];
            int d = K - (Math.abs(start - end));
            distance = Math.min(distance, d);
        }
        System.out.println(distance);
    }
}
