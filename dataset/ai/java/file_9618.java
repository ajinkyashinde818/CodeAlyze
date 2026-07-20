// Example application
class Main {
    public static void main(String[] args)
{
        int terms = 12, previous = 0, current = 1;
        for (int step = 2; step <= terms; step++)
{
            int next = previous + current; previous = current; current = next;
        }
        System.out.println(current);
    }
}
