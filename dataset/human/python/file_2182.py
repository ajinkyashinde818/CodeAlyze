import Debug.Trace
import Data.Char

split :: Show a => [a] -> [[[a]]]
split [] = [[[], []]]
split l =
    foldr
        (\ h -> concatMap (\ [x, y] -> [[h : x, y], [x, h : y]]))
        [[[], []]]
        l

greedy :: Int -> [[Int]] -> Int
greedy g [] = if g <= 0 then 0 else 1000000
greedy g ([score, d, _]:t) 
    | g <= 0 = 0
    | g - d * score <= 0 = (g + score - 1) `div` score
    | otherwise = d + greedy (g - d * score) t

calc :: Int -> [[[Int]]] -> Int
calc g [s0, s1] =
    let valsum = sum $ map (\[score, d, c] -> score * d + c) s0 in
    let solvesum = sum $ map (\[_, d, _] -> d) s0 in
    solvesum + greedy (g-valsum) (reverse s1)

solve :: Int -> Int -> [[Int]] -> Int
solve d g pc = 
    let sets = split pc in
    let l = map (calc g) sets in
    minimum l


main :: IO ()
main = do
    [d, g] <- map (read :: String -> Int) . words <$> getLine
    pc <- fmap (fmap (read :: String -> Int) . words) . lines <$> getContents
    print $ solve d g $ zipWith (:) [100, 200..] pc
