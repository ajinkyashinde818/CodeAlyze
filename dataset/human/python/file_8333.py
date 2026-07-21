import Control.Applicative

main :: IO ()
main = do
  [k, _] <- f
  solve k <$> f >>= print
  where
    f = map read <$> words <$> getLine

solve :: Int -> [Int] -> Int
solve k as = k - maximum ((k - sum ds) : ds)
  where
    ds = (tail >>= zipWith (-)) as
