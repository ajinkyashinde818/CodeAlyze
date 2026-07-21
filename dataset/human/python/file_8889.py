{-# LANGUAGE PatternGuards #-}

import Data.List (stripPrefix)

ps :: [String]
ps = fmap reverse ["dream", "dreamer", "erase", "eraser"]

judge :: String -> Bool
judge "" = True
judge s0
    | Just r <- stripPrefix (head ps) s0 = judge r
    | Just r <- stripPrefix (ps !! 1) s0 = judge r
    | Just r <- stripPrefix (ps !! 2) s0 = judge r
    | Just r <- stripPrefix (ps !! 3) s0 = judge r
    | otherwise = False

main :: IO ()
main = do
    s <- getLine
    putStrLn $ if judge (reverse s) then "YES" else "NO"
