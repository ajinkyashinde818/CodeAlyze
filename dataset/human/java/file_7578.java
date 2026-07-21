import java.lang.reflect.Array;
import java.math.BigDecimal;
import java.util.*;
import java.util.stream.Stream;

public class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        String line = sc.next();
        String[] list = {"eraser", "erase", "dreamer", "dream"};

        for(String l: list){
            line = line.replaceAll(l, "");
        }

        if(line.length() != 0){
            System.out.println("NO");
        } else {
            System.out.println("YES");
        }
    }
}
