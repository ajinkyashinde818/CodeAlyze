import           Control.Monad (replicateM)
import           Data.List     (foldl')

main :: IO ()
main = do
  s <- getLine
  q <- readLn
  qs <- replicateM q getQuery
  putStrLn $ solve s qs

data Query = Reverse | Cons Char | Snoc Char

getQuery :: IO Query
getQuery = do
  (t:xs) <- words <$> getLine
  return $ case t of
    "1" -> Reverse
    "2" -> let [f, c] = xs in case f of
      "1" -> Cons $ head c
      "2" -> Snoc $ head c

solve :: String -> [Query] -> String
solve s qs = toList $ foldl' g (fromList s) qs
  where g xs Reverse  = rev xs
        g xs (Cons c) = cons c xs
        g xs (Snoc c) = snoc xs c

type DoubleList a = ([a], [a])

fromList :: [a] -> DoubleList a
fromList xs = (xs, [])

toList :: DoubleList a -> [a]
toList (xs, ys) = xs ++ reverse ys

rev :: DoubleList a -> DoubleList a
rev (xs, ys) = (ys, xs)

cons :: a -> DoubleList a -> DoubleList a
cons x (xs, ys) = ((x:xs), ys)

snoc :: DoubleList a -> a -> DoubleList a
snoc (xs, ys) x = (xs, (x:ys))
