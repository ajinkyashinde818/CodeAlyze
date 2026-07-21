import Control.Monad
import Data.Maybe
import Data.List
import qualified Data.ByteString.Char8 as C

parseInt :: C.ByteString -> Int
parseInt = fst . fromJust . C.readInt

work :: (Bool, String, String) -> [C.ByteString] -> (Bool, String, String)
work (o, ls, rs) (b : bs) =
  if 1 == parseInt b
    then (not o, rs, ls)
    else let [b1, b2] = bs
             c = C.index b2 0
         in case parseInt b1 of
           1 -> (o, c : ls, rs)
           otherwise -> (o, ls, c : rs)

main :: IO ()
main = do
  s <- C.getLine
  q <- fmap parseInt C.getLine
  qs <- replicateM q $ fmap C.words C.getLine
  let (o, ls, rs) = foldl' work (True, "", "") qs
      s' = (if o then id else C.reverse) s
  C.putStrLn $ C.concat [C.pack ls, s', C.reverse $ C.pack rs]
