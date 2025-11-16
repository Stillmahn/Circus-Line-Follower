// Just writing stuff to share





# Put this in base function
timeSinceLastRun = 0
timeSinceStart = 0
timeAtStart = time()
counter = 0


state = 1


while TRUE {
    timeSinceLastRun = time()-timeAtStart;
    timeSinceStart = timeSinceStart + timeSinceLastRun;
    counter = counter + timeSinceLastRun;

    # Inside one function

    if state == 0 {
        # Go straight
    }

    if state == 1 {
        if sub_state == 0 {
            # Sweep right X
            if counter > X {
                sub_state = 1
                counter = 0
            }
        }
        if sub_state

    }

}