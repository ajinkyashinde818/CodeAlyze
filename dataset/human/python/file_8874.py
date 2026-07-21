import Data.List
import Data.Maybe

main = do
  s <- getLine

  putStrLn $ yesno $ solve s

  where
    solve s
      | s == [] = True
      | isPrefixOf "dream" s =
        let Just r = stripPrefix "dream" s
        in
          if isPrefixOf "er" r then
            or [solve r, solve $ fromJust (stripPrefix "er" r)]
          else
            solve r
      | isPrefixOf "eraser" s = solve $ fromJust (stripPrefix "eraser" s)
      | isPrefixOf "erase" s = solve $ fromJust (stripPrefix "erase" s)
      | otherwise = False
    yesno True = "YES"
    yesno False = "NO"
