import Data.Bool (bool)
import Data.List (sort, sortBy)

main :: IO ()
main = do
    [s,t] <- getParams
    putStrLn $ solve s t

getParams :: IO [String]
getParams = lines <$> getContents

solve :: String -> String -> String
solve s = toAnswer . lessable s

toAnswer :: Bool -> String
toAnswer = bool "No" "Yes"

lessable :: String -> String -> Bool
lessable s t = minS < maxT
  where
    minS = sort s
    maxT = sortBy (flip compare) t
