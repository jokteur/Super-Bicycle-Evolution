from scheduler import Scheduler
from universe import Universe

class Creature:
    _hp = 0
    _neural_network = None

    def __init__(self):
        self._hp = 10
        self._attack = 1
        self._neural_network = NeuralNetwork()
        self._next_action = Wait()

    def act(self):
        self._next_action.resolve()
        self._next_action, dtime = self._make_decision()
        Scheduler.register_event(creature=self, dtime=dtime)

    def lose_hp(self, hp):
        self._hp -= hp
        if self._hp < 0:
            self._die()

    def _make_decision(self):
        external_inputs = Universe.get_vision_of(self)
        return self._neural_network.process(external_inputs)

class NeuralNetwork:
    def process(external_inputs):
        return Attack(external_inputs[0]), 10

class Action:
    pass

class Attack(Action):
    pass

class Wait(Action):
    def resolve(self):
        pass
