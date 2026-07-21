import Data.List
import Data.Maybe (mapMaybe)

solve :: String -> String
solve xs = if null s then xs else solve (head s)
    where s = mapMaybe ((`stripPrefix` xs) . reverse) ["dream", "dreamer", "erase", "eraser"]

main :: IO ()
main = do
    s <- reverse <$> getLine
    putStrLn $ if null (solve s) then "YES" else "NO"
