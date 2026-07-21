import java.util.*;

public class Main {
    public static void main(String[] args){
        Scanner o = new Scanner(System.in);
        int n = o.nextInt();
        int m = o.nextInt();
        int x = o.nextInt();
        int[][] arr = new int[n][m+1];

        for ( int i = 0 ; i < n ; i++ )
        {
            for ( int j = 0 ; j < m+1 ; j++ )
            {
                arr[i][j] = o.nextInt();
            }
        }

        int l = 0;
        int r = (1<<n) - 1;
        int ans = 1000000001;
        while( l <= r )
        {
            int[] c = new int[m+1];
            Arrays.fill(c,0);
            for ( int j = 0 ; j < n ; j++ )
            {
                if ( (l & (1<<j)) == (1<<j) )
                {
                    for ( int k = 0 ; k < m+1 ; k++ )
                    {
                        c[k] += (arr[j][k]);
                    }
                }
            }
            boolean ok = true;
            for ( int i = 1 ; i < m+1 ; i++ )
            {
                if ( c[i] < x )
                {
                    ok = false;
                    break;
                }
            }
            if(ok)
            {
                ans = Math.min(ans,c[0]);
            }
            l++;
        }

        if ( ans == 1000000001 )
        {
            System.out.print("-1");
        }
        else
        {
            System.out.print(ans);
        }
    }
}
