import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;
import java.util.Scanner;
import java.util.Set;

public class Main {

    public static void main(String[] args) {
        
        Scanner sc = new Scanner(System.in);
        
        int n = Integer.parseInt(sc.next());
        long k = Long.parseLong(sc.next());
        int[] a = new int[n+1];
        for(int i = 1; i <= n; i++){
            a[i] = Integer.parseInt(sc.next());
        }
        
        List<Integer> list = new ArrayList<>();
        list.add(1);
        int j = 1;
        for(int i = 1; i <= n; i++){
            j = a[j];
            list.add(j);
        }
        Set<Integer> set = new HashSet<>();
        int b = 0;
        int d = 0;
        for(int i = 0; i < list.size(); i++){
            if(!set.add(list.get(i))){
                b = list.get(i);
                d = i;
                break;
            }
        }
        int c = 0;
        for(int i = 0; i < list.size(); i++){
            if(list.get(i) == b){
                c = i;
                break;
            }
        }
        if(k <= c){
            System.out.println(list.get((int)k));
        }else{
            int e = d-c;
            int f = (int)((k-c)%e);
            System.out.println(list.get(c+f));
        }
    }
}
