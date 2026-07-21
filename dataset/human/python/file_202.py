import Data.List

main :: IO ()
main = readLn >>= printRes . solve
    where
        printRes (b, xs)
            | b = putStrLn "Yes" >> (putStrLn . unlines . map (unwords . map show)) xs
            | otherwise = putStrLn "No"

solve :: Int -> (Bool, [[Int]])
solve n
    | b = (b, [k] : map ((k - 1) :) ss)
    | otherwise = (b, [])
    where
        (b, k) = check $ zip [2..] ns
        ns = scanl1 (+) [1..]
        
        check ((k, x) : xs)
            | x == n = (True, k)
            | n < x = (False, k)
            | otherwise = check xs

        ss = build 2 2 [[1], [1]]

        build len c acc
            | k < 3 = acc
            | len == k = acc
            | otherwise = build (len + 1) (c + len) $ add c acc
            where
                add c (x : xs) = (c : x) : add (c + 1) xs
                add c _ = [[(c - len)..(c - 1)]]
