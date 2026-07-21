import Control.Monad
import Data.Array
import Data.List
import Debug.Trace

type Image = Array (Int,Int) Int

get :: IO (Image, Image)
get = do
  [n,m] <- (map read . words) <$> getLine
  let 
    read' :: Char -> Int
    read' c = if c == '.' then 1 else if c == '#' then 0 else 2
  ns <- (listArray ((1,1),(n,n))) <$> (concat <$> (replicateM n $ map read' <$> getLine))
  ms <- (listArray ((1,1),(m,m))) <$> (concat <$> (replicateM m $ map read' <$> getLine))
  --ms <- (listArray ((1,1),(m,m))) <$> ((concat <$> (forM [1..m] $ \i -> map read')) <$> getLine)
  pure (ns, ms)

solve :: (Image, Image) -> Bool
solve (as,bs) = any (flip go $ range $ bounds bs) $ range $ bounds as
  where
    go _ [] = True
    go ai@(ay,ax) (bi@(by,bx):bis) = 
      if (inRange (bounds as) ai') && a == b then
        go ai bis
      else
        False
      where
        ai' = (ay - 1 + by, ax - 1 + bx)
        a = as ! ai'
        b = bs ! bi

solve' :: (Image, Image) -> Bool
solve' (as,bs) = f (range $ bounds as) (range $ bounds bs)
  where
    f [] _ = False
    f (a:aa) bb =
      if f' a bb then
        True
      else
        f aa bb

    f' _ [] = True
    f' a@(ay,ax) ((b@(by,bx)):bb) =
      if inRange (bounds as) ai && ac == bc  then
        f' a bb
      else
        False
      where
        ai = (ay - 1 + by, ax - 1 + bx)
        ac = as ! ai
        bc = bs ! b

      

main = do
  is <- get
  putStrLn $ 
    if solve' is then
      "Yes"
    else
      "No"
