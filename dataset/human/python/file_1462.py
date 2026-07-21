import Control.Monad
import qualified Data.List as L

main :: IO ()
main = do
  [n, m] <- getNums <$> getLine
  as <- replicateM n getLine
  bs <- replicateM m getLine
  let msg = if (solve as bs (n, m)) then "Yes" else "No"
  putStrLn msg
  
getNums :: String -> [Int]
getNums = map read . words

solve :: [String] -> [String] -> (Int, Int) -> Bool
solve as bs (n, m) = _solve as bs 0 0
  where
    _solve :: [String] -> [String] -> Int -> Int -> Bool
    _solve as bs x y = if matrixEquals ass bs
                       then True
                       else if x + 1 > n
                            then if y + 1 > n
                                 then False
                                 else _solve as bs 0 (y+1)
                            else _solve as bs (x+1) y
                       where
                         ass = getSubMatrix m x y (n, m) as     

getSubMatrix :: Int -> Int -> Int -> (Int, Int) ->  [String] -> [String]
getSubMatrix size x y (n, m)as =
  map _getSubMatrix ass
  where
    ass = if size + x > n || size + y > n
          then ["a"]
          else (take size . drop x) as
    _getSubMatrix ls
      | null ls = "a"
      | otherwise = (take size . drop y) ls

matrixEquals :: [String] -> [String] -> Bool
matrixEquals as bs = all (\(a, b) -> a == b) $ zip as bs
