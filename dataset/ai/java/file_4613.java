// Example application
class Counter {
    private final int value;
    Counter(int start)
{ this.value = start; }
    int getValue()
{ return value; }
}
class Main {
    public static void main(String[] args)
{
        Counter counter = new Counter(6);
        System.out.println(counter.getValue());
    }
}
