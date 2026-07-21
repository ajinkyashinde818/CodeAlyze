import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class Main {
    public static void main(String[] args){
        Scanner scanner = new Scanner(System.in);
        int n = scanner.nextInt();
        int m = scanner.nextInt();
        int x = scanner.nextInt();

        ArrayList<Reference> refs = new ArrayList<>();

        for(int i = 0; i < n; i++){
            Reference ref = new Reference();
            ref.price = scanner.nextInt();
            for(int j = 0; j < m; j++){
                ref.algolisms.add(scanner.nextInt());
            }
            refs.add(ref);
        }

        int[] temp = new int[m];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                temp[j] += refs.get(i).algolisms.get(j);
            }
        }

        int[] ucheck = Arrays.stream(temp).filter(num -> num >= x).toArray();
        if (ucheck.length != temp.length) {
            System.out.println(-1);
            return;
        }
        int[] understangings = new int[m];
        int sum = 0;

        int min1 = dfs(refs, refs.get(0), true, understangings, x, sum, 0);
        int min2 = dfs(refs, refs.get(0), false, understangings, x, sum, 0);

        sum = Math.min(min1, min2);
        System.out.println(sum);
    }

    public static int dfs(ArrayList<Reference> refs, Reference ref, boolean choice, int[] understandings, int x, int sum, int node) {
        int[] understandings1 = understandings.clone();
           if (choice) { //その参考書を選択する場合
                sum += ref.price;
                for (int j = 0; j < understandings1.length; j++) { //参考書を選択したため理解度アップ
                    understandings1[j] += ref.algolisms.get(j);
                }
                int[] ucheck = Arrays.stream(understandings1).filter(num -> num >= x).toArray();
                if (ucheck.length == understandings1.length) { //全てのアルゴリズムの理解度がx以上か確かめる
                    return sum;
                }
            }

        node++;
        int[] understandings2 = understandings1.clone();
        if(node < refs.size()) {
                int sum1 = dfs(refs, refs.get(node), true, understandings1, x, sum, node);
                int sum2 = dfs(refs, refs.get(node), false, understandings2, x, sum, node);
                return Math.min(sum1, sum2);
            }

        if(choice) {
            int[] ucheck = Arrays.stream(understandings1).filter(num -> num >= x).toArray();
            if(ucheck.length != understandings1.length){
                return Integer.MAX_VALUE;
            }
        }else{
            int[] ucheck = Arrays.stream(understandings2).filter(num -> num >= x).toArray();
            if(ucheck.length != understandings2.length){
                return Integer.MAX_VALUE;
            }
        }
        return sum;
    }
}

class Reference{
    int price = 0;
    ArrayList<Integer> algolisms = new ArrayList<>();
}
