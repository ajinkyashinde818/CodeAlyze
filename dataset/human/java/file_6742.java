import java.util.Scanner;
import java.util.List;
import java.util.ArrayList;
import java.util.Collections;
import java.lang.Math;

class Main {
    
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        int k = scanner.nextInt();
        int n = scanner.nextInt();
        List<Integer> list = new ArrayList<>();
        for(int i=0; i<n; i++){
            list.add(scanner.nextInt());
        }
        scanner.close();
        Collections.sort(list);
        List<Integer> resultList = new ArrayList<>();
        for(int i=0; i<n; i++){
            if(i == n-1){
                resultList.add(Math.abs(list.get(0)+k-list.get(n-1)));
            }else{
                resultList.add(Math.abs(list.get(i+1)-list.get(i)));
            }
        }
        Collections.sort(resultList);
        int result = k - resultList.get(n-1);
        System.out.println(result);
    }
}
