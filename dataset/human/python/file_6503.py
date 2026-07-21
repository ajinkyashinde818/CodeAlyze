import Control.Monad


main = do
  n <- getLine
  q <- readLn
  a <- map words <$> replicateM q getLine

  putStrLn $ f2 $ foldl f (True, n, "") a

f :: (Bool, String, String) -> [String] -> (Bool, String, String)
f (flag, l, r) [[c1]]
  | c1 == '1' = (not flag, r, l)
f (flag, l, r) [[c1], [c2], [c]]
  | flag && c2 == '1' = (flag, c : l, r)
  | flag && c2 == '2' = (flag, l, c : r)
  | not flag && c2 == '2' = (flag, l, c : r)
  | otherwise = (flag, c : l, r)

f2 :: (Bool, String, String) -> String
f2 (f, l, r) = l ++ reverse r
