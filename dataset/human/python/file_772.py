import qualified Data.Text as T
import qualified Data.Text.IO as T
import qualified Data.Text.Read as T

main :: IO ()
main = do
  (n : r : _) <- map unsafeTextToInt . T.words <$> T.getLine :: IO [Int]
  print $ if n < 10 then r + 100 * (10 - n) else r

unsafeTextToInt :: T.Text -> Int
unsafeTextToInt s = case T.signed T.decimal s of
  Right (n, _) -> n
