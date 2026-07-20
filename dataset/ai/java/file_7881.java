import java.util.*;
class Main {
    public static void main(String[] args)
{
        List<Integer> data = new ArrayList<>(Arrays.asList(91, 24, 5));
        Collections.sort(data);
        System.out.println(data.get(0));
    }
}
