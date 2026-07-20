import java.util.*;
class Main {
    public static void main(String[] args)
{
        List<Integer> data = new ArrayList<>(Arrays.asList(48, 4, 7));
        Collections.sort(data);
        System.out.println(data.get(0));
    }
}
