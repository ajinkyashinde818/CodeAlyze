import Control.Applicative ((<$>), (<*>))
import Control.Monad
import Data.List

main :: IO ()
main = do
  solve <$> getl (map read . words) >>= print

solve :: [Int] -> Int
solve [k, s] = length $ [x| x <- [0..k], y <- [0..k], let z = s - x - y, z >= 0, z <= k]

getl :: (String -> a) -> IO a
getl f = f <$> getLine
