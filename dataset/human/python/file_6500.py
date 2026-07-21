import Control.Monad
import Prelude

data Query = One | Two Int Char deriving (Show, Eq)


type Queue a = ([a], [a])
type MyStr = Queue Char


empty :: Queue a
empty = ([], [])

check :: [a] -> [a] -> Queue a
check [] r = (reverse r, [])
check f  r = (f, r)

snoc :: Queue a -> a -> Queue a
snoc (f, r) x = check f (x : r)


toList :: Queue a -> [a]
toList (a,b)= a ++ reverse b


sousa :: Query -> MyStr -> MyStr
sousa One (s, t) = (t, s)
sousa (Two 1 c) (s, t) = (c:s, t)
sousa (Two 2 c) str@(s, t) = snoc str c

main = do
  str <- getLine
  q <- read <$> getLine
  qs <- forM [1..q] $ \n -> do
    query <- getLine
    return $ if head query == '1'
       then One
       else let [f, c] = tail (words query) in Two (read f) (head c)
  putStrLn $ toList $ foldl (flip sousa) (str, []) qs
