import java.util.*;
class Main {
    public static void main(String[] args)
{
        List<Integer> data = new ArrayList<>(Arrays.asList(3, 21, 4));
        Collections.sort(data);
        System.out.println(data.get(0));
    }
}
