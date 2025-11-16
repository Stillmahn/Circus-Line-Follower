// Just writing stuff to share






timeSinceLastRun = 0
timeSinceStart = 0
counter = 0


while true:
    timeSinceLastRun = time();
    timeSinceStart = timeSinceStart + timeSinceLastRun;
    counter = counter + timeSinceLastRun;

    # Inside one function

    if counter > 3:
        # 3 seconds has passed

        counter = 0;