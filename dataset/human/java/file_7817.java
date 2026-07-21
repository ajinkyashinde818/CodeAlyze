import java.util.HashMap;
import java.util.Map;
import java.util.Scanner;

public class Main {
    public static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int n=sc.nextInt();
        long k = sc.nextLong();
        int arr[] = new int[n+1];
        for(int i=1;i<=n;i++)
        {
            arr[i] = sc.nextInt();
        }
        long befrep = 0;
        int start =1;
        int tr = 0;
        Map<Integer,Integer> map = new HashMap<>();
        while(true)
        {
            if(map.get(start)==null)
            {
                map.put(start,1);
                tr = start;
                start = arr[start];
                befrep = befrep+1;
            }
            else
            {

                break;
            }
        }

        long rep =1;
        int save =tr;


        while(true)
        {
            if(arr[save]==tr)
            {
                break;
            }
            else
            {
                rep++;
                save = arr[save];
            }
        }

        if(k>befrep) {
            long last = (k - befrep) % rep;
            int fin = tr;
            //int ans;
            for (int i = 0; i < last; i++) {
                fin = arr[fin];
            }
            System.out.println(arr[fin]);
        }
        else
        {
            int ans=0;
            int start2=1;
            for(int i=0;i<k;i++)
            {
                start2=arr[start2];
            }
            System.out.println(start2);
        }


    }
}
