import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.nio.charset.StandardCharsets;
import java.util.*;

public class Main {

    int[] inputArray;
    Set<String> set = new HashSet<>();
    int K;

    public static void main(String[] args) throws IOException {
        new Main().run();
    }

    void run() {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        int m = sc.nextInt();

        List<String> nList = new ArrayList<>();
        List<String> mList = new ArrayList<>();
        boolean check = false;

        for(int i=0; i<n; i++){
            char[] input = sc.next().toCharArray();
            for(char c: input){
                String s = String.valueOf(c);
                nList.add(s);
            }
        }

        for(int i=0; i<m; i++){
            char[] input = sc.next().toCharArray();
            for(char c: input){
                String s = String.valueOf(c);
                mList.add(s);
            }
        }

        int count = 0;

        if(nList.size() == mList.size()){
            for(int j=0; j< mList.size(); j++){
                if(nList.get(j).equals(mList.get(j))){
                    count++;
                    if(count == mList.size()){
                        check = true;
                        break;
                    }
                } else {
                    count = 0;
                }
            }
        } else {
            loop: for(int i=0; i<nList.size()-mList.size(); i++){
                for(int j=0; j< mList.size(); j++){
                    if(nList.get(i+j).equals(mList.get(j))){
                        count++;
                        if(count == mList.size()){
                            check = true;
                            break loop;
                        }
                    } else {
                        count = 0;
                    }
                }
            }
        }

        if(check){
            System.out.println("Yes");
        } else {
            System.out.println("No");
        }
    }

    double manhattan(Ten point1, Ten point2){
        return Math.abs(point1.getX() - point2.getX()) + Math.abs(point1.getY() - point2.getY());
    }

    void substring(String s, int num){
        for(int i=1; i<=num; i++){
            if(i > K){
                break;
            }
            for(int j=0; j<num; j++){
                if(j + i-1 < num){
//                    System.out.println(s.substring(j, j+i));
                    set.add(s.substring(j, j+i));
                } else {
                    break;
                }
            }
        }
    }

    void permutation(String s, String ans){
        if(s.length() <= 1){
            System.out.println(ans + s);
        } else {
            for(int i=0; i<s.length(); i++){
                permutation(s.substring(0, i) + s.substring(i + 1), ans + s.charAt(i));
            }
        }
    }
}

class Ten{
    private int x;
    private int y;

    Ten(int x, int y){
        this.x = x;
        this.y = y;
    }

    public int getX() {
        return x;
    }

    public void setX(int x) {
        this.x = x;
    }

    public int getY() {
        return y;
    }

    public void setY(int y) {
        this.y = y;
    }
}
