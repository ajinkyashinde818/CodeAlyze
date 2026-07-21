import Control.Applicative
import Control.Monad
import Data.List
import Data.Maybe (isJust)

parse :: String -> Maybe String
parse [] = Just ""
parse xs
    | Just ys <- stripPrefix "eraser" xs = Just ys
    | Just ys <- stripPrefix "erase" xs = Just ys
    | Just _ <- stripPrefix "dreamer" xs
        = let Just as = stripPrefix "dream" xs
              Just bs = stripPrefix "dreamer" xs
           in parse as <|> parse bs
    | Just ys <- stripPrefix "dream" xs = Just ys
    | otherwise = Nothing

loop xs = case parse xs of
    Nothing -> Nothing
    Just "" -> Just ""
    Just ys -> loop ys

main :: IO ()
main = do
    ss <- getLine
    if isJust $ loop ss
        then putStrLn "YES"
        else putStrLn "NO"
