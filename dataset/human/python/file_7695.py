import Control.Monad
import Control.Applicative
import Data.List
import qualified Data.Map as Map
import Data.Array
strToInt s = (read :: String -> Int) s

main = do
	x <- readLn :: IO Int
	if x < 1200 then putStrLn "ABC"
				else putStrLn "ARC"
