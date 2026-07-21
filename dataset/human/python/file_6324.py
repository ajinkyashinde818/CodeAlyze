import qualified Data.Text as T
import qualified Data.Text.IO as T
import qualified Data.Text.Read as T
import Data.List (unfoldr)

main :: IO ()
main = do
  (n : _) <- map unsafeSignedDecimal . T.words <$> T.getLine :: IO [Int]
  let
    (q, r) = n `divMod` 2
  print $ if r == 0 then f q else 0

f :: Int -> Int
f = sum . unfoldr next
  where
    next k | q == 0 = Nothing
           | otherwise = Just (q, q)
      where
        q = k `div` 5

unsafeSignedDecimal :: T.Text -> Int
unsafeSignedDecimal s = case T.signed T.decimal s of
  Right (n, _) -> n
