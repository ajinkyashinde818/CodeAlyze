import Control.Applicative
import Control.Monad
import Data.Monoid
import Data.Maybe
import Data.List

main :: IO ()
main = do
    s <- getLine :: IO String
    putStrLn $ if isJust $ parse s then "YES" else "NO"

parse :: String -> Maybe String
parse "" = Just ""
parse s = let
    a = if take (length "dream")   s == "dream"   then Just $ drop (length "dream")   s else Nothing
    b = if take (length "dreamer") s == "dreamer" then Just $ drop (length "dreamer") s else Nothing
    c = if take (length "erase")   s == "erase"   then Just $ drop (length "erase")   s else Nothing
    d = if take (length "eraser")  s == "eraser"  then Just $ drop (length "eraser")  s else Nothing
    in (parse =<< a) <|> (parse =<< b) <|> (parse =<< c) <|> (parse =<< d)
