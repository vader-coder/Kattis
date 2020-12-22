f1 = open("sim.h", "r")
f2 = open("sim.cpp", "r")
simh = f.read()
simcpp = f.read()

totalText = simh + "\n" + simcpp
total = open("total.cpp", "w")
total.write()
