import qualified Data.Text as T
import qualified Data.Text.IO as T
import qualified Data.Text.Read as T

main :: IO ()
main = do
  (k : n : _) <- map unsafeTextToInt . T.words <$> T.getLine :: IO [Int]
  let
    rotate :: [Int] -> [Int]
    rotate (x : xs) = xs ++ [x + k]
  as <- map unsafeTextToInt . T.words <$> T.getLine :: IO [Int]
  let
    ds = zipWith subtract <$> id <*> rotate $ as :: [Int]
    m = maximum ds :: Int
  print $ k - m

unsafeTextToInt :: T.Text -> Int
unsafeTextToInt s = case T.signed T.decimal s of
  Right (n, _) -> n
