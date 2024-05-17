# DAEMON

This module setups a thread that calls MCMAN card detect routine once a minute.

Something inside the card detect routine is resetting the arcade watchdog on the syscon if a valid security dongle is detected.

A more decent approach to satisfy the watchdog is highly needed. since this module causes issues on dongle I/O, even on DONGLEMAN versions wich have additional semaphores on that function...