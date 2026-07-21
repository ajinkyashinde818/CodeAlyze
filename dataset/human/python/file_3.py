import qualified Data.Text as T
import qualified Data.Text.IO as T
import qualified Data.Text.Read as T

main :: IO ()
main = do
  (r : g : b : n : _) <- map unsafeSignedDecimal . T.words <$> T.getLine :: IO [Int]
  let
    list = do
      let r' = n `div` r
      i <- [0..r']
      let g' = (n - r * i) `div` g
      j <- [0..g']
      return $ (n - r * i - g * j) `mod` b
  print . length . filter (== 0) $ list

unsafeSignedDecimal :: T.Text -> Int
unsafeSignedDecimal s = case T.signed T.decimal s of
  Right (n, _) -> n
