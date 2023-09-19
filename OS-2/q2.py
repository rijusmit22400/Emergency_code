import matplotlib.pyplot as plt
import matplotlib.ticker as ticker
import numpy as np

y_axis = np.array([])


f = open("data.txt","r")
for i in f.readlines():
    ls = i.split(":")
    y_axis = np.append(y_axis , float(ls[1].rstrip("\n")))
f.close()
x_axis = np.array(["SCHED_OTHER","SCHED_FIFO","SCHED_RR"])
plt.bar(x_axis, y_axis, color="green", tick_label=x_axis, width=0.998, edgecolor= "black")
plt.title("Process Scheduling")
plt.xlabel("Policies")
plt.ylabel("Time Taken")
plt.gca().yaxis.set_major_formatter(ticker.FormatStrFormatter("%.f"))
plt.show()