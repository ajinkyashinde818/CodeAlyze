import Control.Applicative
import Control.Monad
import Data.List

main :: IO ()
main = do
    [k, s] <- fmap read . words <$> getLine :: IO [Int]
    let as = do
        x <- [0 .. k]
        y <- [0 .. k]
        let z = s - x - y
        guard (0 <= z && z <= k)
        return 1
    print $ sum as
