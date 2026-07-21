import Data.List (sort)

main :: IO ()
main = do
  [r,g,b,n] <- map (read :: String -> Int) . words <$> getLine
  print $ ans n r g b

ans :: Int -> Int -> Int -> Int -> Int
ans n a b c = let k = div n a in foldl func 0 [0..k] where
  func acc l = acc + split (n-a*l) b c

split :: Int -> Int -> Int -> Int
split n a b = let k = div n a in foldl func 0 [0..k] where
  func acc l = if (n-a*l) `mod` b == 0 then acc + 1 else acc
