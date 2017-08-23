from numpy.random import rand

class Creature:
    config = None
    _hp = 0
    _neural_network = None
    _id = 0

    def __init__(self, universe=None, parents=None):
        if parents is None:
            self.universe = universe
            self._id = Creature._id
            Creature._id += 1

            for attr, bounds in Creature.config["attributes"].items():
                setattr(self, attr, rand()*(bounds[1] - bounds[0]) + bounds[0])

            self._hp = self.HP_max
            self._neural_network = NeuralNetwork(self)
            self._next_action = Wait()

        if parents is not None:
            self.universe = parents[0].universe
            # more cloning stuff

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
            return Attack(power=self.owner.attack,
                          target=external_inputs[0]), 10
        else:
            return None, 0

class Action:
    def resolve(self):
        pass

class Attack(Action):
    def __init__(self, power=None, target=None):
        self.power = power
        self.target = target

    def resolve(self):
        self.target.lose_hp(self.power)

class Move(Action):
    def __init__(self, creature=None, time=0):
        self.creature = creature
        self.time = time

    def resolve(self):
        pass

class Turn(Action):
    def __init__(self, creature=None, time=0):
        self.creature = creature
        self.time = time

    def resolve(self):
        pass

class Wait(Action):
    pass
