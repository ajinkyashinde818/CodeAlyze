import Data.Bool
import qualified Data.ByteString.Char8 as C

main = sol . C.reverse <$> C.getLine >>= putStrLn . (bool "NO" "YES")

sol s
  | C.null s                = True
  | ts!!0 `C.isPrefixOf` s  = sol $ C.drop (C.length (ts!!0)) s
  | ts!!1 `C.isPrefixOf` s  = sol $ C.drop (C.length (ts!!1)) s 
  | ts!!2 `C.isPrefixOf` s  = sol $ C.drop (C.length (ts!!2)) s
  | ts!!3 `C.isPrefixOf` s  = sol $ C.drop (C.length (ts!!3)) s
  | otherwise               = False

ts = (C.reverse . C.pack) <$> ["dream","dreamer","erase","eraser"]
