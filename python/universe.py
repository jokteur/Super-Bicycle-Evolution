from scheduler import Scheduler

class Universe:
    creatures = []
    def __init__(self):
        self.creatures.extend([Creature(), Creature()])
        timer = 0
        for crea in self.creatures:
            Scheduler.register_event(creature=crea, dtime=timer)
            timer += 1

    @classmethod
    def get_vision_of(cls, creature):
        for crea in cls.creatures:
            if crea != creature:
                return [crea]
