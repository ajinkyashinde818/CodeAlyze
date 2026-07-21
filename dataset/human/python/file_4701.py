{-# OPTIONS_GHC -O2 -funbox-strict-fields #-}
import           Data.List (sort)

main :: IO ()
main = do
  s <- getLine
  t <- getLine
  putStrLn . showResult $ solve s t

showResult True  = "Yes"
showResult False = "No"

solve s t = sort s < reverse (sort t)
