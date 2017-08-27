import numpy as np
import time
from numpy.random import rand

class Network:
    def __init__(self):
        self.signal = np.zeros((5, 15))
        self.weights = rand(4, 15, 15)
        self.layers = rand(4, 15)

    def makeDecision(self, inp):
        self.signal[0] = inp
        for i in range(0, len(self.layers) - 1):
            self.signal[i+1] = np.tanh(np.add(np.matmul(self.weights[i], self.signal[i]), self.layers[i+1]))
        return self.signal

t0 = time.time()
net = Network()
for i in range(100000):
    inp = rand(15)
    dec = net.makeDecision(inp)

print(time.time() - t0)
