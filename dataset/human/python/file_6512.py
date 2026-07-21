import Control.Monad
import Data.Maybe
import qualified Data.ByteString.Char8 as BS
import Data.List

readInt = fst . fromJust . BS.readInt
getInt = readInt <$> BS.getLine

main = do
    s <- getLine
    q <- getInt
    queues <- map words <$> replicateM q getLine
    putStrLn . rev s $ foldl solve (True, [], []) queues

rev s (b, l, r) | b = l ++ s ++ (reverse r)
                | not b = r ++ (reverse s) ++ (reverse l)

solve (b, l, r) q
    | t == '1'                        = (not b, l, r)
    | t == '2' && f == '1' && b       = (b, c : l, r)
    | t == '2' && f == '1' && (not b) = (b, l, c : r)
    | t == '2' && f == '2' && b       = (b, l, c : r)
    | t == '2' && f == '2' && (not b) = (b, c : l, r)
    where (t : _) = q !! 0
          (f : _) = q !! 1
          (c : _) = q !! 2
