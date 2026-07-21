import java.util.Scanner;

public class Main {
  public static void main(String[] args) {
    Scanner scan = new Scanner(System.in);
    String str_scan = scan.nextLine();
    // int型へ変換
    var N = Integer.parseInt(str_scan);

    String[] D = new String[N];

    for(var j=0;j < N;j++){
      D[j] = scan.nextLine();
    }

    int zoro = 0;
    var ans = "No";
    String[] DiceLine = new String[2];

    for (var i=0;i < N;i++){
      DiceLine = D[i].split(" ");
      if (DiceLine[0].equals(DiceLine[1])){
        zoro++;
      }else{
        zoro = 0;
      }

      if(zoro == 3){
        ans = "Yes";
      }
    }

    System.out.println(ans);
    scan.close();
  }
}
