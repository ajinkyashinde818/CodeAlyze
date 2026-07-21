import Control.Monad
import Data.Maybe
import qualified Data.ByteString.Char8 as BS

tuplify2 (x:y:_) = (x,y)
tuplify2 _ = undefined

--Input functions with ByteString
readInt = fst . fromJust . BS.readInt
readIntTuple = tuplify2 . map readInt . BS.words
readIntList = map readInt . BS.words

getInt = readInt <$> BS.getLine
getIntList = readIntList <$> BS.getLine
getIntNList n = map readIntList <$> replicateM (fromIntegral n) BS.getLine
getIntMatrix = map readIntList . BS.lines <$> BS.getContents
getIntTuple = readIntTuple <$> BS.getLine
getIntNTuples n = map readIntTuple <$> replicateM (fromIntegral n) BS.getLine
getIntTuples = map readIntTuple . BS.lines <$> BS.getContents
main :: IO ()
main = do
    s <- getLine
    q <- getInt
    query <- map words <$> replicateM q getLine
    putStrLn $ ans $ foldl f (s, "") query

f :: (String, String) -> [String] -> (String, String)
f (l, r) [[c1]]
    | c1=='1' = (r, l)
f (l, r) [[c1],[c2],[c3]]
    | c2 == '1' = (c3:l, r)
    | c2 == '2' = (l, c3:r)
ans :: (String, String) -> String
ans (l, r) = l ++ reverse r
