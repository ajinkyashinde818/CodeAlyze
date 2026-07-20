import java.util.*;
class Main {
    public static void main(String[] args) {
        List<Integer> data = new ArrayList<>(Arrays.asList(10, 24, 9));
        Collections.sort(data);
        System.out.println(data.get(0));
    }
}
