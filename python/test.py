import numpy as np
import time

class ANN:
    """docstring for ANN."""
    def __init__(self, inputs, outputs):
        self.layers = [inputs, outputs]
        self.signal = [inputs, outputs]
        self.weights = [np.random.uniform(-1,1, size=(outputs.size, inputs.size))]

    def addLayer(self, layer):
        self.layers.append(layer)
        self.signal.append(layer)
        self.weights.pop()

        self.weights.append(np.random.uniform(-1, 1, size=(layer.size, self.layers[-2].size)))
        self.weights.append(np.random.uniform(-1, 1, size=(self.layers[-1].size, layer.size)))


    def makeDecision(self, inp):
        self.signal[0] = inp
        for i in range(0, len(self.layers) - 1):
            self.signal[i+1] = np.tanh(np.add(np.matmul(self.weights[i], self.layers[i]), self.layers[i+1]))
        return self.signal

height = 15
inputs = np.random.uniform(-1, 1, height)
outputs = np.random.uniform(-1, 1, height)
brain = ANN(inputs, outputs)
brain.addLayer(np.random.uniform(-1,1,height))
brain.addLayer(np.random.uniform(-1,1,height))
brain.addLayer(np.random.uniform(-1,1,height))

a = np.random.uniform(-1,1,height)
start = time.time()
for i in range(0, 1000000):
    brain.makeDecision(a)
end = time.time()
print(1000000/(end-start))
