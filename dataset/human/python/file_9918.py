import qualified Data.Text as T
import qualified Data.Text.IO as T
import qualified Data.Text.Read as T

main :: IO ()
main = do
  (a : b : _) <- map unsafeSignedDecimal . T.words <$> T.getLine :: IO [Int]
  print $ lcm a b

unsafeSignedDecimal :: T.Text -> Int
unsafeSignedDecimal s = case T.signed T.decimal s of
  Right (n, _) -> n
