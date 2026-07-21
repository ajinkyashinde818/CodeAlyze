import           Data.Maybe
import qualified Data.ByteString.Char8 as B

main :: IO ()
main = uncurry solve . tuple <$> readParams >>= print

readParams :: IO [Int]
readParams = map readInt . B.words <$> B.getLine

readInt :: B.ByteString -> Int
readInt = fromJust . fmap fst . B.readInt

tuple :: [a] -> (a, a)
tuple [a,b] = (a,b)

solve :: Int -> Int -> Int
solve = lcm
