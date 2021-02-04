f1 = open("sim.h", "r")
f2 = open("sim.cpp", "r")
simh = f1.read()
simcpp = f2.read()
#simcpp = f2.readlines()[1:]#leave out include statement

totalText = simh + "\n" + simcpp
total = open("total.cpp", "w")
total.write(totalText)
