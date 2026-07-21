import Control.Monad.State
import Control.Arrow
import Data.Maybe
import Data.List

getInts = map read . words <$> getLine :: IO [Int]

dayDream [] = Just ()
dayDream ('m':'a':'e':'r':'d':a) = dayDream a
dayDream ('r':'e':'m':'a':'e':'r':'d':a) = dayDream a
dayDream ('r':'e':'s':'a':'r':'e':a) = dayDream a
dayDream ('e':'s':'a':'r':'e':a) = dayDream a
dayDream _ = Nothing

main = do
    str <- reverse <$> getLine
    if isJust $ dayDream str then putStrLn "YES" else putStrLn "NO"
-- main = undefined
