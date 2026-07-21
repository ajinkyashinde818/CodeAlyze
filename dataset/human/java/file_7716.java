import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        long k = sc.nextLong();
        int[] a = new int[n];
        for(int i=0;i<n;i++){
            a[i] = sc.nextInt()-1;
        }
        int[] time = new int[n];    //何回目のテレポで初めてその町に到達したかを示す 町番号は箱の番号+1
        time[0] = 0;    //今見たらこれいらなかったね
        int now = 0;    //今いる場所。forループの終わりで毎回更新する
        for(int i=1;;i++){      //2番目の条件がないので無限ループ式。確実にbreakできるとわかっている時以外はマネしないでね。iはステップ数。
            if(time[a[now]] != 0){  //0じゃなければ一度来たことがあるので、その場合...
                int loop = i - time[a[now]];    //ループ長は（現在のステップ数-前回この町に来た時に記録したステップ数）で表される
                k -= (k - i) / loop * loop;     //k回テレポートするのも、k - (k - i)/loop*loop回移動するのも結果は変わらないよね、ってことでkの値そのものを書き換えてしまう
                time = new int[n];  //到達履歴を消去してしまう（このあとループを考慮する必要がないため）
            }else {
                time[a[now]] = i;   //まだ来たことがなかった場合はtimeに何回目に来たことがあるかを記録するが、前のif文がtrueだとtimeを初期化している(2行前)のでその場合もこっちに来る。その場合この分を踏んでいる事には特に意味はない
            }
            now = a[now];
            if(i == k){     //k回「と同等のテレポート回数」(編集済み!!)のテレポートが終わったらbreakする。
                break;
            }
        }
        now++;
        System.out.println(now);    //そうすると素直にテレポートを繰り返した結果みたいな形で答えが出せるのです。
    }
}
