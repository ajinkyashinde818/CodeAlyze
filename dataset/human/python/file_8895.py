import Control.Applicative ((<$>), (<*>))
import Control.Monad
import Data.List

main :: IO ()
main = do
  solve <$> getLine >>= putStrLn

solve :: String -> String
solve xs = f $ reverse xs
  where
    f "" = "YES"
    f ss | length ss >= 5 && take 5 ss == "maerd" = f (drop 5 ss)
         | length ss >= 5 && take 5 ss == "esare" = f (drop 5 ss)
         | length ss >= 6 && take 6 ss == "resare" = f (drop 6 ss)
         | length ss >= 7 && take 7 ss == "remaerd" = f (drop 7 ss)
         | otherwise = "NO"
