import java.util.*;
class Main {
    public static void main(String[] args) {
        List<Integer> data = new ArrayList<>(Arrays.asList(40, 8, 5));
        Collections.sort(data);
        System.out.println(data.get(0));
    }
}
