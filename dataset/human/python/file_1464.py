import Data.List

main = do
  li <- getLine
  let [n,m] = map read $ words li
  co <- getContents
  let (as,bs) = splitAt n $ lines co
  let ans = compute n m as bs
  putStrLn $ if ans then "Yes" else "No"

compute :: Int -> Int -> [String] -> [String] -> Bool
-- compute n m as bs = any (bs ==) $ concatMap (transpose . map (cut n m)) $ cut n m as
compute n m as bs = not $ null
  [ ()
  | as1 <- cut n m as
  , bs1 <- transpose $ map (cut n m) as1
  , bs1 == bs ]

-- cut n m xs : 長さnのリストxsから、長さmの部分リストを全て切り出す
cut :: Int -> Int -> [a] -> [[a]]
cut n m xs = map (take m) $ take (n-m+1) $ tails xs
