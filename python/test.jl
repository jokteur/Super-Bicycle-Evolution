L = 15

weights = Array{Matrix}(4)
layers = Array{Vector}(4)
for i in 1:4
    weights[i] = rand(L, L)
    layers[i] = rand(L)
end

signal = zeros(L)

function decide(inp)
    signal = inp
    for i in 1:4
        signal = tanh(weights[i] * signal)
    end
    return signal
end

@time for i in 1:100000
    inp = rand(L)
    decision = decide(inp)
end
