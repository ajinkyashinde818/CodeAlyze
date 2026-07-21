import java.util.*;

public class Main {
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        
        String[] split = sc.nextLine().split(" ");
        
        int A = Integer.parseInt(split[0]);
        int B = Integer.parseInt(split[1]);
        int K = Integer.parseInt(split[2]);
        
        List<Integer> list = new ArrayList<Integer>();
        
        for(int i = 1; i < 101; i++){
            if(A % i == 0 && B % i == 0){
                list.add(i);
            }
        }
        
        System.out.println(list.get(list.size() - K));
    }
}
