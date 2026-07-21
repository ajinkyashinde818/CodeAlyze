import Control.Monad

cut :: Int -> Int -> Int -> Int -> [String] -> [String]
cut x y w h ss = take h . drop y $ map (take w . drop x) ss

main :: IO ()
main = do
  [n, m] <- map read . words <$> getLine
  ns <- replicateM n getLine
  ms <- replicateM m getLine
  let nw = length $ head ns
  let nh = length ns
  let mw = length $ head ms
  let mh = length ms
  let result = (not . null) $ filter (==True) [cut x y mw mh ns == ms | x <- [0..nw-mw], y <- [0..nh-mh]]
  putStrLn $ if result then "Yes" else "No"
