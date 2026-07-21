import Control.Applicative
import Control.Monad
import Data.Array

f :: Array (Int, Int) Char -> Int -> (Int, Int) -> String
f as m (h, w) = do
    i <- [h .. h + m - 1]
    j <- [w .. w + m - 1]
    return $ as ! (i, j)

main :: IO ()
main = do
    [n, m] <- fmap read . words <$> getLine
    as <- listArray ((1, 1), (n, n)) . concat <$> replicateM n getLine
    bs <- concat <$> replicateM m getLine
    let ps = [(i, j) | i <- [1 .. n - m + 1], j <- [1 .. n - m + 1]]
    if any ((== bs) . f as m) ps
        then putStrLn "Yes"
        else putStrLn "No"
