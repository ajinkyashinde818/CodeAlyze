import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
 
 
public class Main {
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        int a = Integer.parseInt(scanner.next());
        int b = Integer.parseInt(scanner.next());
        int k = Integer.parseInt(scanner.next());
        scanner.close();
        List<Integer> list1 = new ArrayList<Integer>();
        List<Integer> list2 = new ArrayList<Integer>();
        List<Integer> res = new ArrayList<Integer>();
        for(int i = 1; i <= a ; i++){
            if(a%i == 0) list1.add(i);
        }
        for(int i = 1; i <= b ; i++){
            if(b%i == 0) list2.add(i);
        }
        for(Integer u : list1){
            if(list2.contains(u)){
                res.add(u);
            }
        }
 
        System.out.println(res.get(res.size() - k));
    }
}
