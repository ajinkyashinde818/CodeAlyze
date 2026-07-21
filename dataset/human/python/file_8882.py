import Data.List

prefixes = map reverse ["dream", "dreamer", "erase", "eraser"]
matcher s = filter (\x -> isPrefixOf x s) prefixes

matching "" = "YES"
matching str =
  let x = matcher str
  in if length x  > 0 then matching $ drop (length . head $ x) str else "NO"

main = getLine >>= putStrLn . matching . reverse
