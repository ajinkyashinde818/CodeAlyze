import qualified Data.Text as T
import qualified Data.Text.IO as T
import qualified Data.Text.Read as T
import qualified Data.Array as A

main :: IO ()
main = do
  (n : _) <- map unsafeSignedDecimal . T.words <$> T.getLine :: IO [Int]
  as <- map unsafeSignedDecimal . T.words <$> T.getLine :: IO [Int]
  bs <- map unsafeSignedDecimal . T.words <$> T.getLine :: IO [Int]
  cs <- A.listArray (1, pred n) . map unsafeSignedDecimal . T.words <$> T.getLine :: IO (A.Array Int Int)
  let
    is = fst . foldl step ([], Nothing) $ as
    step (is, Just i) a | a == succ i = (i : is, Just a)
                        | otherwise = (is, Just a)
    step _ a = ([], Just a)
  print $ sum bs + sum (map (cs A.!) is)

unsafeSignedDecimal :: T.Text -> Int
unsafeSignedDecimal s = case T.signed T.decimal s of
  Right (n, _) -> n
