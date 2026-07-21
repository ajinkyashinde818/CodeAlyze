import qualified Data.ByteString.Char8 as B
import qualified Data.Map              as M

main :: IO ()
main = do
  _ <- getLine
  s <- B.getLine
  print $ solve s

solve :: B.ByteString -> Integer
solve = pred . M.foldr (%*%) 1 . M.map succ . B.foldr (\c mp -> M.insertWith (+) c 1 mp) M.empty
  where
    x %*% y = ((x `mod` 1000000007) * (y `mod` 1000000007)) `mod` 1000000007
