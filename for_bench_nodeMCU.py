"""

* References:
 => BIPES Virtual Lab by Rafael Aroca: http://www.bipes.net.br/beta2/ui/
  
* Results:
 => No LED:    17977ms (avg)
 => With LED: 114363ms (avg)

"""

import time
import machine

tic = int(0)
i = int(0)
tac = int(0)
state = False

# No LED, 1000000 iterations
tic = time.ticks_ms()
for i in range(1, 1000001):
  pass
tac = time.ticks_ms()
print('Sem LED: ', tac - tic, 'ms, ', i, 'iterations')

# With LED, 1000000 iterations
tic = time.ticks_ms()
for i in range(1, 1000001):
  if i >= 500000:
    if state:
      machine.Pin((2), machine.Pin.OUT).on() # Turn built-in led on
      state = not state
    else:
      machine.Pin((2), machine.Pin.OUT).off() # Turn built-in led off
      state = not state
tac = time.ticks_ms()

print('Com LED: ', tac - tic, 'ms,', i, 'iterations')
