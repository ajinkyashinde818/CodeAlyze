import java.util.*;
class Main
{
    public static void main(String[] args)
    {
        Scanner sc = new Scanner(System.in);
        
        int k = sc.nextInt();
        int n = sc.nextInt();
        int[] param = new int[n];
        int[] param1 = new int[n];
        
        for(int i=0 ; i<n ; i++){
            param[i] = sc.nextInt();
        }
        
        for(int i=0 ; i<n-1 ; i++){
            param1[i] = param[i+1]-param[i]; 
        }
        
        param1[n-1] = (k-param[n-1]) + (param[0]);
        
        
       Arrays.sort(param1);
       
       int dis = k-param1[n-1];
       
       System.out.println(dis);
      }
    }
