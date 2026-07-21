import Data.List
import Data.Char
import Data.Maybe
import Control.Monad
import qualified Data.ByteString.Char8 as BS8

main :: IO ()
main = do
  [k, n] <- unfoldr (BS8.readInteger . BS8.dropWhile isSpace) <$> BS8.getLine
  a <- unfoldr (BS8.readInteger . BS8.dropWhile isSpace) <$> BS8.getLine

  let
    d = map (\(x, y) -> y - x) $ zip a $ (tail a) ++ ([k + head a])

  print $ (sum d) - (maximum d)
