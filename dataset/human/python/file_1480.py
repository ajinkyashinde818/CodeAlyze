import Control.Monad
import Data.List

main = do
    [n,m] <- map read . words <$> getLine
    a <- replicateM n getLine
    b <- replicateM m getLine
    putStrLn $ if null [()| i <- [0..n-m], j <- [0..n-m], check (map (drop j) (drop i a)) b] then "No" else "Yes"

check x y = and $ zipWith (\a b -> b `isPrefixOf` a) x y
