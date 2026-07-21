import java.util.List;
import java.util.Scanner;
import java.util.stream.Collectors;
import java.util.stream.IntStream;
import java.util.stream.Stream;

public class Main {
    public static void main(String[] args) {
        Scanner std = new Scanner(System.in);
        int count = Integer.parseInt(std.nextLine());
        Stream<Integer> meals = IntStream.range(0, count).map(it -> std.nextInt()).boxed();
        Stream<Integer> satisfactionLevels = IntStream.range(0, count).map(it -> std.nextInt()).boxed();
        Stream<Integer> extraSatisfactionLevels = IntStream.range(0, count - 1).map(it -> std.nextInt()).boxed();

        System.out.println(totalSatisfaction(meals.collect(Collectors.toList()),
                satisfactionLevels.collect(Collectors.toList()),
                extraSatisfactionLevels.collect(Collectors.toList())));
    }

    private static int totalSatisfaction(List<Integer> meals,
                                         List<Integer> levels,
                                         List<Integer> extraLevels) {
        int totalLevel = IntStream.range(0, meals.size())
                .reduce(0, (acc, index) -> {
                    Integer meal = meals.get(index);
                    Integer level = levels.get(meal - 1);
                    acc += level;
                    if (index > 0) {
                        Integer beforeMeal = meals.get(index - 1);
                        if (meal - beforeMeal == 1) {
                            Integer extraLevel = extraLevels.get(beforeMeal - 1);
                            acc += extraLevel;
                        }
                    }

                    return acc;
                });

        return totalLevel;
    }
}
