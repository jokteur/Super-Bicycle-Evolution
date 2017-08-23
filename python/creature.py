class Creature:
    _hp = 0
    _neural_network = None
    _id = 0

    def __init__(self, universe):
        self.universe = universe
        self._id = Creature._id
        Creature._id += 1

        self._hp = 10
        self.attack = 1
        self._neural_network = NeuralNetwork(self)
        self._next_action = Wait()

    def __repr__(self):
        return "Creature {} [hp = {}]".format(self._id, self._hp)

    def act(self):
        self._next_action.resolve()
        self._next_action, dtime = self._make_decision()
        if self._next_action is not None:
            self.universe.schedule.register_event(creature=self, dtime=dtime)

    def lose_hp(self, hp):
        print("{} suffers".format(self))
        self._hp -= hp
        if self._hp < 0:
            self._die()

    def _make_decision(self):
        external_inputs = self.universe.get_vision_of(self)
        return self._neural_network.process(external_inputs)

    def _die(self):
        print("{} dies".format(self))
        self.universe.remove(self)

class NeuralNetwork:
    def __init__(self, owner):
        self.owner = owner
    def process(self, external_inputs):
        if external_inputs is not None:
            return Attack(attacker=self.owner,
                          target=external_inputs[0]), 10
        else:
            return None, 0

class Action:
    def resolve(self):
        pass

class Attack(Action):
    def __init__(self, attacker=None, target=None):
        self.attacker = attacker
        self.target = target

    def resolve(self):
        self.target.lose_hp(self.attacker.attack)

class Wait(Action):
    pass
