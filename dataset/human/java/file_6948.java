import java.util.*;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int k = sc.nextInt();
        int n = sc.nextInt();
        ArrayList<Integer> array = new ArrayList<>();
        for (int i = 0; i < n; i++) {
            array.add(sc.nextInt());
        }
        int max = 0;
        for (int i = 0; i < n - 1 ; i++) {
            if ((array.get(i + 1) - array.get(i)) > max){
                max = (array.get(i + 1) - array.get(i));
            }
        }
        int b = array.get(0) + (k - array.get(n - 1));
        max = max < b ? b : max;
        System.out.println(k - max);
    }
}
