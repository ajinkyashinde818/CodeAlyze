import Control.Monad

main = do
  [d, g] <- map read . words <$> getLine
  pcs <- replicateM d $ map (read :: String -> Int) . words <$> getLine
  print $ solve g d $ reverse pcs

solve :: Int -> Int -> [[Int]] -> Int
solve _ _ [] = 1001
solve g i ([p,c]:pcs)
  | g <= 0         = 0
  | g <= p*i*100   = min ((g + (i*100) - 1) `div` (i*100)) (solve g (i-1) pcs)
  | g <= p*i*100+c = min p (solve g (i-1) pcs)
  | otherwise      = min (p + (solve (g-p*i*100-c) (i-1) pcs)) (solve g (i-1) pcs)
