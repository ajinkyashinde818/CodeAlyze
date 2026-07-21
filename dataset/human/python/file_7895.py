import Control.Monad
import Text.Printf
import Control.Applicative
import Data.List as L

main :: IO()
main = do
  str <- getLine
  printf "%s" $ slv str

slv :: String -> String
slv str | L.sort str == "abc" = "Yes"
        | otherwise = "No"
