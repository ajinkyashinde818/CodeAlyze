import java.util.ArrayList;
import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;

public class Main {
    public static void main(String[] args){
        Scanner scan = new Scanner(System.in);
        int K=scan.nextInt();
        int N=scan.nextInt();
        List<Integer> houseDist=new ArrayList<Integer>();
        for(int i=0;i<N;i++){
            houseDist.add(scan.nextInt());
        }
        List<Integer> sortedDist = houseDist.stream().sorted().collect(Collectors.toList());
        List<Integer> betweenHouse = new ArrayList<Integer>();
        for(int i=1;i<N;i++){
            betweenHouse.add(sortedDist.get(i)-sortedDist.get(i-1));
        }
        betweenHouse.add(sortedDist.get(0)+(K-sortedDist.get(N-1)));
        int max = betweenHouse.stream().mapToInt(value -> value).max().getAsInt();
        int sum = betweenHouse.stream().mapToInt(value -> value).sum() - max;
        System.out.println(sum);
    }
}
