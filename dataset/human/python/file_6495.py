import           Control.Monad
import           Data.Bits
import qualified Data.ByteString.Char8 as BS
import           Data.Maybe

readInt = fst . fromJust . BS.readInt
readIntList = map readInt . BS.words
getInt = readInt <$> BS.getLine
getIntList = readIntList <$> BS.getLine

getQuery = do
  l <- words <$> getLine
  case l of
    ["1"]           -> return (1, 0, 'x')
    ["2", n, (c:_)] -> return (2, (read n :: Int), c)

main = do
  s <- getLine
  n <- getInt
  qs <- replicateM n getQuery

  let solve :: String -> String -> Int -> [(Int, Int, Char)] -> BS.ByteString
      solve h t m [] = let s' = BS.pack s
                           h' = BS.pack h
                           t' = BS.pack t
                           s'' = BS.append (BS.append h' s') (BS.reverse t')
                       in
                         if (m .&. 1) == 1 then BS.reverse s'' else s''
      solve h t m ((1,_,_):qs') = solve h t (m+1) qs'
      solve h t m ((2,f,c):qs') =
        if (f == 1 && (m .&. 1) == 0) || (f == 2 && (m .&. 1) == 1)
        then solve (c:h) t m qs'
        else solve h (c:t) m qs'

  BS.putStrLn $ solve "" "" 0 qs
