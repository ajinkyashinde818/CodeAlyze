import Control.Monad

main :: IO ()
main = do
  mn <- getLine
  if mn == "0 0"
    then return ()
    else do
      let [m,n] = map (read :: String -> Int) (words mn)
      ls <- replicateM n readLn
      let ans = solve m ls
      print ans
      main


solve :: Int -> [Int] -> Int
solve m ls = check m ls (maximum ls) 1500000
  where
    check :: Int -> [Int] -> Int -> Int -> Int
    check m ls mini maxi
      | mini == maxi = mini
      | rank ls width > m = check m ls (width+1) maxi
      | otherwise = check m ls mini width
      where
        width = (mini + maxi) `div` 2
        rank :: [Int] -> Int -> Int
        rank ls width = rank' ls width 0 1
          where
            rank' :: [Int] -> Int -> Int -> Int -> Int
            rank' [] _ _ count = count
            rank' (x:xs) width nowwidth count
              | x + nowwidth > width = rank' xs width x (count + 1)
              | otherwise = rank' xs width (x + nowwidth) count
