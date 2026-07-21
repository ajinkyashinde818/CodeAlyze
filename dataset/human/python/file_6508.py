import Data.List as List
import Control.Monad


data State =
  State
    { head :: String -- [tail, ... ,head]
    , tail :: String -- [head, ... ,tail]
    }
  deriving (Show)


main = do
  s <- (\h -> State h "") <$> getLine
  q <- readLn :: IO Int
  qs <- getQueries q
  let res = executeQueries qs s
  putStrLn $ stateToString res


stateToString :: State -> String
stateToString (State { Main.head = h, Main.tail = t }) =
  h ++ (reverse t)

executeQueries :: [Query] -> State -> State
executeQueries queries initialState =
  let 
      help [] state = state
      help (q:qs) state = help qs (executeQuery q state)
  in
    help queries initialState
  

executeQuery :: Query -> State -> State
executeQuery query (State { Main.head = h, Main.tail = t }) =
  case query of
    Reverse ->
       State t h
    PushHead c ->
       State (c:h) t
    PushTail c ->
       State h (c:t)


data Query
  = Reverse
  | PushHead Char
  | PushTail Char
  deriving (Show)

getQueries :: Int -> IO [Query]
getQueries n =
  replicateM n (stringToQuery <$> getLine)
  where
    stringToQuery s =
        let xs = words s
        in
          if List.head xs == "1" then
             Reverse
          else
              let [_, f, c] = xs
              in
                if f == "1" then
                  PushHead (List.head c)
                else
                  PushTail (List.head c)
