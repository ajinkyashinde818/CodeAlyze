import java.util.*;

class Main{
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int k = sc.nextInt();
        int n = sc.nextInt();
        List<Integer> list = new ArrayList<>();
        long max = 0;

        for(int i = 0;i < n;i++){
            int dis = sc.nextInt();
            list.add(dis);
        }

        if(list.contains(0)){
            max = k- list.get(n-1);
        }else{
            max = k - list.get(n-1) + list.get(0);
        }

        for(int i = 1;i < n;i++){
            long distance = list.get(i)-list.get(i-1);
            if(distance>max){
                max = distance;
            }
        }
        
        System.out.println(k-max);
    }
}
