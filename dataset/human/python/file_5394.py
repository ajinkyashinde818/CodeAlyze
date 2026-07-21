import Control.Monad
import Control.Applicative
import Debug.Trace

main :: IO ()
main = do
  m <- readLn :: IO Int
  replicateM_ m $ do
    (n, (fs, ls)) <- getInput
    let fs' = flatten fs
        ls' = flatten ls
        len = length (filter (== 'Y') (fs' ++ ls'))
--    trace (fs' ++ "," ++ ls') (return ())
    let add1 = if lastY fs' ls'
               then 0
               else 1
    let ans = len + n + add1 +
          if lastY (reverse fs') (reverse ls')
          then 0
          else 1
    print ans

getInput = do
  n <- readLn :: IO Int
  (fs, ls) <- splitAt (2*n) <$> getLine
  return (n, (fs, ls))

flatten :: String -> String
flatten str@(s:ss) = s : go (tail str)
  where
    go [] = []
    go [x] = [x]
    go (x:y:z) = case (x, y) of
                   ('N', 'N') -> 'N' : go z
                   (_, _) -> 'Y' : go z

lastY :: String -> String -> Bool
lastY (x:xs) (y:ys) = case (x, y) of
                        ('Y', _) -> True
                        (_, 'Y') -> False
                        (_, _) -> lastY xs ys
