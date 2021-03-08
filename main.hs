-- import the State monad
import Control.Monad.State

-- create an alias type FibState that represents a triple:
-- (prevPrev (pp), prev (p), current value (v))
-- using Integer type to allow for unbounded integers
type FibState = (Integer, Integer, Integer)

-- state transformation function that uses a FibState type
-- wrapped in the State monad and returns an integer value
fib_st :: State FibState Integer
fib_st =
  -- getState returns the state by extracting the passed prevPrev, 
  -- prev, and the current value and sequencing (>>=) these values
  -- into the tuple which are then used within the conditionals
  getState >>= \(pp, p, v) -> 
    -- when current value == 0, return prevPrev
    if v == 0
      then return pp
    -- else, update the current state: 
    -- prevPrev = prev; prev = prevPrev + prev;  
    -- current value gets decremented
    -- use >> since we need to sequence into fib_st from
    -- putState which carries no return value
    else putState (p, pp + p, v - 1) >> fib_st

  where
    -- getter that uses the State monad to wrap a FibState type,
    -- i.e. the current state and uses an anonymous function
    -- to return its value
    getState :: State FibState FibState
    getState = state (\(pp, p, v) -> ((pp, p, v), (pp, p, v)))

    -- setter that takes a FibState value and updates the state;
    -- does not return anything, ()
    putState :: FibState -> State FibState ()
    putState (pp', p', v') = state (\_ -> ((), (pp', p', v')))

-- run fibonacci takes in Integer and returns an Integer
run_fib :: Integer -> Integer
-- pattern where fst returns the result of runState extracting 
-- the function from fib_st and applies it to the initial state (0, 1, v)
run_fib v = fst (runState fib_st (0, 1, v))