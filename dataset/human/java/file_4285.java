import java.util.Scanner;
import java.util.stream.Stream;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int n = Integer.parseInt(sc.nextLine());
        String str  = sc.nextLine();
        String[] astr = str.split(" "); //状況に合わせて
        int[] a = Stream.of(astr).mapToInt(x->{
            try{
                return Integer.parseInt(x) -1;
            }
            catch(Exception e){
                e.printStackTrace();
            }
            return 0;
        }).toArray();
        String str2  = sc.nextLine();
        String[] astr2 = str2.split(" "); //状況に合わせて
        int[] b = Stream.of(astr2).mapToInt(x->{
            try{
                return Integer.parseInt(x);
            }
            catch(Exception e){
                e.printStackTrace();
            }
            return 0;
        }).toArray();

        String str3  = sc.nextLine();
        String[] astr3 = str3.split(" "); //状況に合わせて
        int[] c = Stream.of(astr3).mapToInt(x->{
            try{
                return Integer.parseInt(x);
            }
            catch(Exception e){
                e.printStackTrace();
            }
            return 0;
        }).toArray();
        sc.close();
        int manzoku = 0;
        int before = 21;
        for(int i=0;i<a.length;i++){
            manzoku += b[a[i]];
            //System.out.println(b[a[i]]);
            if(before +1 == a[i]){
                manzoku += c[a[i-1]];
                //System.out.println(c[a[i-1]]);
            }
            before = a[i];
        }
        System.out.println(manzoku);
    }
}
