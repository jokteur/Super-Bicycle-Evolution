from schedule import Schedule
from creature import Creature

MAX_CURRENT_TIME = 100

class Universe:
    creatures = []
    def __init__(self):
        self.creatures.extend([Creature(self), Creature(self)])
        self.schedule = Schedule()
        timer = 0
        for crea in self.creatures:
            self.schedule.register_event(creature=crea, dtime=timer)
            timer += 1

    def get_vision_of(self, creature):
        for crea in self.creatures:
            if crea != creature:
                return [crea]
        return None

    def remove(self, creature):
        self.creatures.remove(creature)
        self.schedule.remove(creature)

    def run(self):
        while len(self.schedule) > 0 and self.schedule.current_time < MAX_CURRENT_TIME:
            print(self.schedule)
            current_creature = self.schedule.next_creature()
            current_creature.act()  # Prochaine action dans l'event ou dans la créature ?


if __name__ == '__main__':
    universe = Universe()
    universe.run()
    print("Exited normally")
