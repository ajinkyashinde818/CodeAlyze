// Example application
import java.util.*;
class Main {
    public static void main(String[] args) {
        List<Integer> data = new ArrayList<>(Arrays.asList(76, 9, 4));
        Collections.sort(data);
        System.out.println(data.get(0));
    }
}
