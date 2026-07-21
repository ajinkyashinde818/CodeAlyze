import java.util.*;

class Main{
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int N = 3;
        //入力の格納
        int[]a = new int[N];
        for(int i = 0; i < N; i++){
            a[i] = sc.nextInt();
        }
        sc.close();
        //公約数の格納リスト
        ArrayList<Integer> list = new ArrayList<Integer>();
        //1<=Aより1から
        // for(int i = 1; i <= 100; i++){
        //     //A、Bがiで割り切れたとき＝公約数の時
        //     if((a[0] % i == 0) && (a[1] % i == 0)){
        //         list.add(i);
        //     }
        // }
        //何番目に大きいものなので上から回す(降順で格納）
        for(int i = 100; 1 <= i; i--){
            //A、Bがiで割り切れたとき＝公約数の時
            if((a[0] % i == 0) && (a[1] % i == 0)){
                list.add(i);
            }
        }
        //get(a)=a番目の要素なので1引いて合わせる
        System.out.println(list.get(a[2] - 1));
    }
}
